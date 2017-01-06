#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <algorithm>

using namespace cv;
using namespace std;

double kernel[9] = { 0.0625, 0.125, 0.0625, 0.125, 0.25, 0.125, 0.0625, 0.125, 0.0625 };

int isValid(Mat img, int x, int y)
{
	if (x < 0 || y < 0 || x >= img.rows || y >= img.cols)
		return 0;
	else return 1;
}

int main()
{
	int i, j, k, l, m;
	double sum;

	Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\veg.jpg", 0);

	Mat a(img.rows, img.cols, CV_8UC1, Scalar(0));

	for (i = 1; i < img.rows - 1; i++)
	{
		for (j = 1; j < img.cols - 1; j++)
		{
			sum = 0;
			for (m = -1, k = 0; m < 2; m++)
			{
				for (l = -1; l < 2; l++)
				{
					if (isValid(img, i + m, j + l))
					{
						sum += (img.at<uchar>(i + m, j + l))*(kernel[k++]);
					}
				}
			}
			a.at<uchar>(i, j) = sum;
		}
	}
	namedWindow("abc", WINDOW_AUTOSIZE);
	namedWindow("def", WINDOW_AUTOSIZE);

	imshow("abc", img);
	imshow("def", a);

	waitKey(0);

	return 0;
}