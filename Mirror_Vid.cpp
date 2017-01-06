#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j;

	VideoCapture vid(0);

	Mat temp, a;

	while (1)
	{
		vid.read(temp);

		a = temp.clone();
		Mat b(a.rows, 2 * a.cols, CV_8UC3, Scalar(255, 255, 255));

		namedWindow("Vid", WINDOW_AUTOSIZE);

		for (i = 0; i < a.rows; i++)
		{
			for (j = 0; j < a.cols; j++)
			{
				b.at<Vec3b>(i, j)[0] = a.at<Vec3b>(i, j)[0];
				b.at<Vec3b>(i, j)[1] = a.at<Vec3b>(i, j)[1];
				b.at<Vec3b>(i, j)[2] = a.at<Vec3b>(i, j)[2];
			}

			for (j = a.cols; j < 2 * a.cols; j++)
			{
				b.at<Vec3b>(i, j)[0] = a.at<Vec3b>(i, 2 * a.cols - 1 - j)[0];
				b.at<Vec3b>(i, j)[1] = a.at<Vec3b>(i, 2 * a.cols - 1 - j)[1];
				b.at<Vec3b>(i, j)[2] = a.at<Vec3b>(i, 2 * a.cols - 1 - j)[2];
			}
		}

		imshow("Vid", b);

		int z = waitKey(1);
		if (z == (int) 'e')
			break;
	}
	return 0;
}