#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <algorithm>

using namespace cv;
using namespace std;

int isValid(Mat img, int x, int y)
{
	if (x < 0 || y < 0 || x >= img.rows || y >= img.cols)
		return 0;
	else return 1;
}

int main()
{
	int i, j, k, l, m, A[25] = { 0 }, sum;

	Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\lena_n.png", 0);

	Mat a(img.rows, img.cols, CV_8UC1, Scalar(0));

	for (i = 2; i < img.rows - 2; i++)
	{
		for (j = 2; j < img.cols - 2; j++)
		{
			for (m = -2, k = 0; m < 3; m++)
			{
				for (l = -2; l < 3; l++)
				{
					if (isValid(img, i + m, j + l))
						A[k++] = img.at<uchar>(i + m, j + l);
				}
			}

			sum = 0;
			for (k = 0; k < 25; k++)
			{
				sum += A[k];
			}
			a.at<uchar>(i, j) = sum / 25;

		}
	}
	namedWindow("abc", WINDOW_AUTOSIZE);
	namedWindow("def", WINDOW_AUTOSIZE);

	imshow("abc", img);
	imshow("def", a);

	waitKey(0);

	return 0;
}


