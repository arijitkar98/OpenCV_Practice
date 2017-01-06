#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j, k;

	Mat img = imread("C:\\Users\\ariji\\Desktop\\image.jpg", 1);

	Mat a(img.rows, 2*(img.cols), CV_8UC3, Scalar(0, 0, 0));

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			for (k = 0; k < 3; k++)
			{
				a.at<Vec3b>(i, j)[k] = img.at<Vec3b>(i, j)[k];
			}

		}
	}


	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			for (k = 0; k < 3; k++)
			{
				a.at<Vec3b>(i, img.cols + j)[k] = img.at<Vec3b>(i, (img.cols - 1 - j))[k];
			}

		}
	}

	namedWindow("abc", WINDOW_AUTOSIZE);
	namedWindow("def", WINDOW_AUTOSIZE);

	imshow("abc", img);
	imshow("def", a);
	waitKey(0);

	return 0;
}


