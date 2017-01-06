#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j, k;

	Mat img = imread("C:\\Users\\ariji\\Desktop\\15232163_1033549500088026_1777183304498018268_n.jpg", 1);

	Mat a(img.rows, img.cols, CV_8UC3, Scalar(0, 0, 0));

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			for (k = 0; k < 3; k++)
			{
				if (img.at<Vec3b>(i, j)[k] > 214)
					a.at<Vec3b>(i, j)[k] = 255;
				else a.at<Vec3b>(i, j)[k] = img.at<Vec3b>(i, j)[k] + 40;
			}

		}
	}

	namedWindow("abc", WINDOW_AUTOSIZE);
	namedWindow("def", WINDOW_AUTOSIZE);

	imshow("abc", img);
	imshow("def", a);
	waitKey(0);

	return 0;
}


