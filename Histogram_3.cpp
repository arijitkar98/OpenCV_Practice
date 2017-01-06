#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j, k, B1[256] = { 0 }, G1[256] = { 0 }, R1[256] = { 0 };

	Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\test1.png", 1);

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			B1[img.at<Vec3b>(i, j)[0]]++;
			G1[img.at<Vec3b>(i, j)[1]]++;
			R1[img.at<Vec3b>(i, j)[2]]++;
		}
	}

	for (i = 0; i < 256; i++)
	{
		B1[i] = B1[i] / 10;
		G1[i] = G1[i] / 10;
		R1[i] = R1[i] / 10;
	}

	Mat B(600, 768, CV_8UC3, Scalar(255, 255, 255));
	Mat G(600, 768, CV_8UC3, Scalar(255, 255, 255));
	Mat R(600, 768, CV_8UC3, Scalar(255, 255, 255));

	for (i = 0; i < 256; i++)
	{
		for (k = 0; k < 3; k++)
		{
			for (j = 0; j < B1[i]; j++)
			{
				B.at<Vec3b>(599 - j, 3 * i + k)[1] = 0;
				B.at<Vec3b>(599 - j, 3 * i + k)[2] = 0;
			}
		}
	}

	for (i = 0; i < 256; i++)
	{
		for (k = 0; k < 3; k++)
		{
			for (j = 0; j < G1[i]; j++)
			{
				G.at<Vec3b>(599 - j, 3 * i + k)[0] = 0;
				G.at<Vec3b>(599 - j, 3 * i + k)[2] = 0;
			}
		}
	}

	for (i = 0; i < 256; i++)
	{
		for (k = 0; k < 3; k++)
		{
			for (j = 0; j < R1[i]; j++)
			{
				R.at<Vec3b>(599 - j, 3 * i + k)[0] = 0;
				R.at<Vec3b>(599 - j, 3 * i + k)[1] = 0;
			}
		}
	}

	namedWindow("Image", WINDOW_AUTOSIZE);
	namedWindow("Histogram_B", WINDOW_AUTOSIZE);
	namedWindow("Histogram_G", WINDOW_AUTOSIZE);
	namedWindow("Histogram_R", WINDOW_AUTOSIZE);

	imshow("Image", img);
	imshow("Histogram_B", B);
	imshow("Histogram_G", G);
	imshow("Histogram_R", R);

	waitKey(0);

	return 0;
}


