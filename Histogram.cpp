#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j, k, A[256] = { 0 };

	Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\test1.png", 0);

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			A[img.at<uchar>(i, j)]++;
		}
	}

	for (i = 0; i < 256; i++)
	{
		A[i] = A[i] / 10;
	}

	Mat a(600, 768, CV_8UC1, Scalar(255));

	for (i = 0; i < 256; i++)
	{
		for (k = 0; k < 3; k++)
		{
			for (j = 0; j < A[i]; j++)
			{
				a.at<uchar>(599 - j, 3 * i + k) = 0;
			}
		}
	}

	namedWindow("Image", WINDOW_AUTOSIZE);
	namedWindow("Histogram", WINDOW_AUTOSIZE);

	imshow("Image", img);
	imshow("Histogram", a);

	waitKey(0);

	return 0;
}


