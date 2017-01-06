#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j, k, l = 0, n = 0, m;

	Mat img = imread("C:\\Users\\ariji\\Desktop\\image.jpg", 1);

	Mat a(img.rows, img.cols, CV_8UC3, Scalar(0, 0, 0));

	namedWindow("abc", WINDOW_AUTOSIZE);
	namedWindow("def", WINDOW_AUTOSIZE);

	createTrackbar("Bright", "def", &l, 200);
	createTrackbar("Dim", "def", &n, 200);

	while (1)
	{

		for (i = 0; i < img.rows; i++)
		{
			for (j = 0; j < img.cols; j++)
			{
				for (k = 0; k < 3; k++)
				{
					if (img.at<Vec3b>(i, j)[k] > 254 - l)
						a.at<Vec3b>(i, j)[k] = 255;
					else a.at<Vec3b>(i, j)[k] = img.at<Vec3b>(i, j)[k] + l;

					if (img.at<Vec3b>(i, j)[k] < n)
						a.at<Vec3b>(i, j)[k] = 0;
					else a.at<Vec3b>(i, j)[k] = img.at<Vec3b>(i, j)[k] - n;
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


