#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j, a[256] = { 0 }, pos;
	long total, sum;

	Mat img = imread("C:\\Users\\ariji\\Desktop\\a.png", 0);

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			a[img.at<uchar>(i, j)]++;
		}

	}

	total = (img.rows * img.cols);
	sum = 0;
	pos = 0;
	i = 0;

	while (1)
	{
		sum = sum + a[i];
		pos = i;
		i++;
		if (sum > (total / 2))
			break;
	}

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			if (img.at<uchar>(i, j) > pos)
				img.at<uchar>(i, j) = 255;
			else img.at<uchar>(i, j) = 0;
		}
	}
	namedWindow("abc", WINDOW_AUTOSIZE);

	imshow("abc", img);

	waitKey(0);

	return 0;
}


