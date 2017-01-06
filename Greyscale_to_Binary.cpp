#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j;

	Mat a = imread("C:\\Users\\ariji\\Desktop\\image.jpg", 0);

	Mat b(a.rows, a.cols, CV_8UC1, Scalar(0));

	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
		{
			if (a.at<uchar>(i, j) > 127)
				b.at<uchar>(i, j) = 255;
			else b.at<uchar>(i, j) = 0;
		}
	}


	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Binary", WINDOW_AUTOSIZE);

	imshow("Original", a);
	imshow("Binary", b);

	waitKey(0);

	return 0;
}