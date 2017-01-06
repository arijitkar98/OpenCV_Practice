#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <algorithm>
#include <math.h>
#include <stack>


using namespace cv;
using namespace std;

int main()
{
	int i, j, b = 0, g = 0, r = 0, e = 0, x, y, z, w;

	Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\b.jpg", 1);

	Mat bin(img.rows, img.cols, CV_8UC1, Scalar(0));

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Binary", WINDOW_AUTOSIZE);

	createTrackbar("Blue", "Binary", &b, 255);
	createTrackbar("Green", "Binary", &g, 255);
	createTrackbar("Red", "Binary", &r, 255);
	createTrackbar("Error", "Binary", &e, 255);

	while (1)
	{
		for (i = 0; i < img.rows; i++)
		{
			for (j = 0; j < img.cols; j++)
			{
				x = img.at<Vec3b>(i, j)[0];
				y = img.at<Vec3b>(i, j)[1];
				z = img.at<Vec3b>(i, j)[2];

				if (x >= (b - e) && x <= (b + e) && y >= (g - e) && y <= (g + e) && z >= (r - e) && z <= (r + e))
					bin.at<uchar>(i, j) = 255;
				else bin.at<uchar>(i, j) = 0;
			}
		}

		imshow("Original", img);

		imshow("Binary", bin);

		w = waitKey(50);
		if (w == (int)'e')
			break;
	}
	return 0;
}