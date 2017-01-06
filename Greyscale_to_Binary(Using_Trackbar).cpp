#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j, k = 0, l;

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Binary", WINDOW_AUTOSIZE);

	createTrackbar("Threshold", "Binary", &k, 255);

	Mat a = imread("C:\\Users\\ariji\\Desktop\\image.jpg", 0);

	Mat b(a.rows, a.cols, CV_8UC1, Scalar(0));

	while (1)
	{

		for (i = 0; i < a.rows; i++)
		{
			for (j = 0; j < a.cols; j++)
			{
				if (a.at<uchar>(i, j) > k)
					b.at<uchar>(i, j) = 255;
				else b.at<uchar>(i, j) = 0;
			}
		}

		imshow("Original", a);
		imshow("Binary", b);

		l = waitKey(50);
		if (l == 0)
			break;

	}
	return 0;
}