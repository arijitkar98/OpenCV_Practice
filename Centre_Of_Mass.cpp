#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <algorithm>
#include <math.h>


using namespace cv;
using namespace std;

Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\binary.png", 0);

Mat visited(img.rows, img.cols, CV_8UC1, Scalar(255));

int cnt;

struct COM{
	int x, y;
} Com[5];

int isValid(Mat img, int x, int y)
{
	if (x < 0 || y < 0 || x >= img.rows || y >= img.cols)
		return 0;
	else return 1;
}

void DFS_VISIT(int i, int j)
{
	int k, l;

	visited.at<uchar>(i, j) = (255 / (cnt + 1));

	for (k = i - 1; k < i + 2; k++)
	{
		for (l = j - 1; l < j + 2; l++)
		{
			if (isValid(img, k, l))
			{
				if ((visited.at<uchar>(k, l) == 255) && (img.at<uchar>(k, l) == 255))
					DFS_VISIT(k, l);
			}
		}
	}
}

int main()
{
	int i, j, k;
	int sumx[5] = { 0 }, sumy[5] = { 0 }, total[5] = { 0 };

	cnt = 1;

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			if ((visited.at<uchar>(i, j) == 255) && (img.at<uchar>(i, j) == 255))
			{
				DFS_VISIT(i, j);
				cnt++;
			}
		}
	}

	for (k = 0; k < cnt - 1; k++)
	{
		for (i = 0; i < visited.rows; i++)
		{
			for (j = 0; j < visited.cols; j++)
			{
				if (visited.at<uchar>(i, j) == 255 / (k + 2))
				{
					sumx[k] += i;
					sumy[k] += j;
					total[k]++;
				}
			}
		}
	}

	for (k = 0; k < cnt - 1; k++)
	{
		Com[k].x = (sumx[k]) / total[k];
		Com[k].y = (sumy[k]) / total[k];

		printf("COM of Blob %d : (%d,%d) \n", k + 1, Com[k].x, Com[k].y);
	}


	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Blob", WINDOW_AUTOSIZE);

	imshow("Original", img);

	imshow("Blob", visited);


	waitKey(0);
	return 0;
}