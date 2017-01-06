#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j;

	Mat a = imread("C:\\Users\\ariji\\Desktop\\a.png", 1);

	Mat b(a.rows, a.cols, CV_8UC3, Scalar(0, 0, 0));

	for (i = 0; i < a.rows; i++)
	{
		for (j = 0; j < a.cols; j++)
		{
			if (a.at<Vec3b>(i, j)[2] > 100 && a.at<Vec3b>(i, j)[0] < 55 && a.at<Vec3b>(i, j)[1] < 55)
			{
				b.at<Vec3b>(i, j)[0] = a.at<Vec3b>(i, j)[0];
				b.at<Vec3b>(i, j)[1] = a.at<Vec3b>(i, j)[1];
				b.at<Vec3b>(i, j)[2] = a.at<Vec3b>(i, j)[2];
			}
			else {
				b.at<Vec3b>(i, j)[0] = 0;
				b.at<Vec3b>(i, j)[1] = 0;
				b.at<Vec3b>(i, j)[2] = 0;
			}
		}
	}


	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("New", WINDOW_AUTOSIZE);

	imshow("Original", a);
	imshow("New", b);

	waitKey(0);

	return 0;
}