#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j, k = 0, l = 0, m = 0, n;

	Mat a = imread("C:\\Users\\ariji\\Desktop\\a.png", 1);

	Mat b(a.rows, a.cols, CV_8UC3, Scalar(0, 0, 0));

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("New", WINDOW_AUTOSIZE);

	createTrackbar("Red", "New", &k, 255);
	createTrackbar("Blue", "New", &l, 255);
	createTrackbar("Green", "New", &m, 255);

	while (1)
	{

		for (i = 0; i < a.rows; i++)
		{
			for (j = 0; j < a.cols; j++)
			{
				if (a.at<Vec3b>(i, j)[2] > k && a.at<Vec3b>(i, j)[0] < l && a.at<Vec3b>(i, j)[1] < m)
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



		imshow("Original", a);
		imshow("New", b);

		n = waitKey(50);
		if (n == 0)
			break;
	}
	return 0;
}