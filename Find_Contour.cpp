#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <vector>

using namespace cv;
using namespace std;

int main()
{
	int i, j;

	Mat a = imread("C:\\Users\\ariji\\Desktop\\Extra\\binary3.png", 0);
	Mat b;

	vector< vector<Point> > v;
	vector<Vec4i>heirarchy;

	Canny(a, b, 30, 100, 3);

	findContours(b, v, heirarchy, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

	Mat c(a.rows, a.cols, CV_8UC1, Scalar(0));

	for (i = 0; i < v.size(); i++)
	{
		for (j = 0; j < v[i].size(); j++)
		{
			c.at<uchar>(v[i][j].y, v[i][j].x) = 255;
		}
	}

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Binary", WINDOW_AUTOSIZE);

	imshow("Original", a);
	imshow("Binary", c);

	waitKey(0);

	return 0;
}