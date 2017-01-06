#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j, k;

	Mat a = imread("C:\\Users\\ariji\\Desktop\\image.jpg", 1);

	Mat b = imread("C:\\Users\\ariji\\Desktop\\image.jpg", 0);

	Mat c(a.rows, a.cols, CV_8UC1, Scalar(0));

	Mat d(a.rows, a.cols, CV_8UC1, Scalar(0));

	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
		{
			c.at<uchar>(i, j) = (a.at<Vec3b>(i, j)[0] + a.at<Vec3b>(i, j)[1] + a.at<Vec3b>(i, j)[2]) / 3;
		}
	}


	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
		{
			d.at<uchar>(i, j) = (0.114)*(a.at<Vec3b>(i, j)[0]) + (0.587)*(a.at<Vec3b>(i, j)[1]) + (0.299)*(a.at<Vec3b>(i, j)[2]);
		}
	}

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Direct_Greyscale", WINDOW_AUTOSIZE);
	namedWindow("Average", WINDOW_AUTOSIZE);
	namedWindow("Formula", WINDOW_AUTOSIZE);

	imshow("Original", a);
	imshow("Direct_Greyscale", b);
	imshow("Average", c);
	imshow("Formula", d);
	waitKey(0);

	return 0;
}