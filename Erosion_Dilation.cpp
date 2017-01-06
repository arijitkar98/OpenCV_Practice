#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int isValid(Mat img, int x, int y)
{
	if (x < 0 || y < 0 || x >= img.rows || y >= img.cols)
		return 0;
	else return 1;
}

void erosion(Mat img1, Mat img2)
{
	int i, j, k, l;

	for (i = 0; i < img1.rows; i++)
	{
		for (j = 0; j < img1.cols; j++)
		{
			if (img1.at<uchar>(i, j) == 255)
			{
				for (k = -1; k < 2; k++)
				{
					for (l = -1; l < 2; l++)
					{
						if (isValid(img1, i + k, j + l))
						{
							if (img1.at<uchar>(i + k, j + l) == 0)
							{
								img2.at<uchar>(i, j) = 0;
								break;
							}
						}
					}
				}
			}
		}
	}
}

void dilation(Mat img1, Mat img2)
{
	int i, j, k, l;

	for (i = 0; i < img1.rows; i++)
	{
		for (j = 0; j < img1.cols; j++)
		{
			if (img1.at<uchar>(i, j) == 0)
			{
				for (k = -1; k < 2; k++)
				{
					for (l = -1; l < 2; l++)
					{
						if (isValid(img1, i + k, j + l))
						{
							if (img1.at<uchar>(i + k, j + l) == 255)
							{
								img2.at<uchar>(i, j) = 255;
								break;
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
	Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\filter.png", 0);

	Mat img1 = img.clone();

	erosion(img, img1);

	Mat img2 = img1.clone();

	dilation(img1, img2);

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Erosion", WINDOW_AUTOSIZE);
	namedWindow("Dilation", WINDOW_AUTOSIZE);

	imshow("Original", img);
	imshow("Erosion", img1);
	imshow("Dilation", img2);

	waitKey(0);

	return 0;
}