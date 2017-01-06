#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <algorithm>
#include <math.h>

#define SQ(x) (x)*(x) 

using namespace cv;
using namespace std;

struct point{
	int x, y;
};

int main()
{
	int i, j, k = 0;
	long int d;

	point a[1000];

	Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\pentagon.png", 0);

	Mat b(2 * sqrt(SQ(img.rows) + SQ(img.cols)) + 1, 180, CV_8UC1, Scalar(0));

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			if (img.at<uchar>(i, j) == 255)
			{
				a[k].x = i;
				a[k].y = j;
				k++;
			}
		}
	}

	for (i = 0; i < k; i++)
	{
		for (j = 0; j < 180; j++)
		{
			d = ((a[i].x)*cos((CV_PI*j) / 180) + (a[i].y)*sin((CV_PI*j) / 180));
			if (d < 0)
				d += sqrt(SQ(img.rows) + SQ(img.cols));
			if (b.at<uchar>((int)(d), j) + 5 > 255)
				(b.at<uchar>((int)(d), j)) = 255;
			else (b.at<uchar>((int)(d), j)) += 5;
		}
	}

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("D-O", WINDOW_AUTOSIZE);

	imshow("Original", img);

	imshow("D-O", b);

	waitKey(0);

	return 0;
}