#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <algorithm>
#include <math.h>

#define SQ(x) (x)*(x) 
#define z 30

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
	int i, j, k, l, m, n, p = 0;
	long int d;
	int x[10], y[10];

	Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\pentagon.png", 0);

	Mat b(2 * sqrt(SQ(img.rows) + SQ(img.cols)) + 1, 180, CV_8UC1, Scalar(0));

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			if (img.at<uchar>(i, j) == 255)
			{
				for (k = 0; k < 180; k++)
				{
					d = ((i)*cos((CV_PI*k) / 180) + (j)*sin((CV_PI*k) / 180));
					if (d < 0)
						d += sqrt(SQ(img.rows) + SQ(img.cols));
					if (b.at<uchar>((int)(d), k) + 1 > 255)
						(b.at<uchar>((int)(d), k)) = 254;
					else (b.at<uchar>((int)(d), k)) += 1;
				}
			}
		}
	}

	for (i = 0; i < b.rows; i++)
	{
		for (j = 0; j < b.cols; j++)
		{
			if (b.at<uchar>(i, j) >= z)
			{
				m = 0; n = 0;
				for (k = i - 8; k < i + 9; k++)
				{
					for (l = j - 8; l < j + 9; l++)
					{
						if (isValid(b, k, l))
						{
							if (b.at<uchar>(i, j) >= b.at<uchar>(k, l))
							{
								m++;
							}
							n++;
						}
					}
				}
				if (m == n)
				{
					x[p] = i;
					y[p] = j;
					p++;
				}
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf(" (%d) (%d,%d) \n", (i + 1), x[i], y[i]);
	}

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("D-O", WINDOW_AUTOSIZE);

	imshow("Original", img);

	imshow("D-O", b);

	waitKey(0);

	return 0;
}