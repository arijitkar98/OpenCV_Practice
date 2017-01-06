#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j, k, l, n = 1, m;

	Mat img = imread("C:\\Users\\ariji\\Desktop\\image.jpg", 1);

	namedWindow("abc", WINDOW_AUTOSIZE);
	namedWindow("def", WINDOW_AUTOSIZE);

	createTrackbar("Zoom", "def", &n, 10);

	while (1)
	{
		if (n == 0)
			break;

		Mat a(n * img.rows, n * img.cols, CV_8UC3, Scalar(0, 0, 0));

		for (i = 0; i < img.rows; i++)
		{
			for (j = 0; j < img.cols; j++)
			{
				for (k = 0; k < n; k++)
				{
					for (l = 0; l < n; l++)
					{
						a.at<Vec3b>(n * i + k, n * j + l)[0] = img.at<Vec3b>(i, j)[0];
						a.at<Vec3b>(n * i + k, n * j + l)[1] = img.at<Vec3b>(i, j)[1];
						a.at<Vec3b>(n * i + k, n * j + l)[2] = img.at<Vec3b>(i, j)[2];
					}
				}
			}
		}

		imshow("abc", img);
		imshow("def", a);

		m = waitKey(50);
		if (m == (int) 'e')
			break;
	}
	return 0;
}


