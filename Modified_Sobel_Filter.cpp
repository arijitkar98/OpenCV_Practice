#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <algorithm>
#include <math.h>


using namespace cv;
using namespace std;

int kernel_gx[9] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
int kernel_gy[9] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };

int isValid(Mat img, int x, int y)
{
	if (x < 0 || y < 0 || x >= img.rows || y >= img.cols)
		return 0;
	else return 1;
}

int main()
{
	int i, j, k, l, m, n, z = 0;
	int sum_gx, sum_gy, sum = 0;

	Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\test1.png", 0);

	Mat a(img.rows, img.cols, CV_8UC1, Scalar(0));
	Mat b(img.rows, img.cols, CV_8UC1, Scalar(0));

	namedWindow("abc", WINDOW_AUTOSIZE);
	namedWindow("def", WINDOW_AUTOSIZE);
	namedWindow("ghi", WINDOW_AUTOSIZE);

	createTrackbar("Edges", "ghi", &z, 255);

	while (1)
	{
		for (i = 0; i < img.rows; i++)
		{
			for (j = 0; j < img.cols; j++)
			{
				sum_gx = 0, sum_gy = 0;
				for (m = -1, k = 0; m < 2; m++)
				{
					for (l = -1; l < 2; l++)
					{
						if (isValid(img, i + m, j + l))
						{
							sum_gx += (img.at<uchar>(i + m, j + l))*(kernel_gx[k]);
							sum_gy += (img.at<uchar>(i + m, j + l))*(kernel_gy[k]);
							k++;
						}
					}
				}
				sum = sqrt(sum_gx*sum_gx + sum_gy*sum_gy);
				a.at<uchar>(i, j) = (sum) / 4;
			}
		}


		for (i = 0; i < img.rows; i++)
		{
			for (j = 0; j < img.cols; j++)
			{
				if (a.at<uchar>(i, j) > z)
					b.at<uchar>(i, j) = 255;
				else b.at<uchar>(i, j) = 0;
			}
		}

		imshow("abc", img);
		imshow("def", a);
		imshow("ghi", b);

		n = waitKey(50);
		if (n == (int)'e')
			break;
	}
	return 0;
}


