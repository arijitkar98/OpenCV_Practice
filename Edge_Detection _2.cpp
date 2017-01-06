#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <algorithm>
#include <math.h>


using namespace cv;
using namespace std;

int main()
{
	int i, j, k, l, m, n, z = 0, A[9] = { 0 }, MAX, MIN;

	Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\a.png", 0);

	Mat a(img.rows, img.cols, CV_8UC1, Scalar(0));
	Mat b(img.rows, img.cols, CV_8UC1, Scalar(0));

	namedWindow("abc", WINDOW_AUTOSIZE);
	namedWindow("def", WINDOW_AUTOSIZE);
	namedWindow("ghi", WINDOW_AUTOSIZE);

	createTrackbar("Edges", "ghi", &z, 255);

	while (1)
	{
		for (i = 1; i < img.rows - 1; i++)
		{
			for (j = 1; j < img.cols - 1; j++)
			{
				for (m = -1, k = 0; m < 2; m++)
				{
					for (l = -1; l < 2; l++)
					{
						A[k++] = img.at<uchar>(i + m, j + l);
					}
				}
				MAX = -1; MIN = 256;
				for (n = 0; n < 9; n++)
				{
					if (A[n] > MAX)
						MAX = A[n];
					if (A[n] < MIN)
						MIN = A[n];
				}
				a.at<uchar>(i, j) = (MAX - MIN);
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

	imwrite("C:\\Users\\ariji\\Desktop\\Extra\\A1.png", a);

	return 0;
}


