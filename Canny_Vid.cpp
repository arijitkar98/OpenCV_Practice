#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	VideoCapture vid(0);
	int i, j;
	Mat temp, a;

	/*	createTrackbar("Low", "Vid", &x, 1000);
	createTrackbar("High", "Vid", &y, 1000);
	*/
	namedWindow("Vid", WINDOW_AUTOSIZE);

	while (1)
	{
		vid.read(temp);

		a = temp.clone();
		Mat b(a.rows, a.cols, CV_8UC3, Scalar(255, 255, 255));
		Mat c(a.rows, a.cols, CV_8UC1, Scalar(255));

		for (i = 0; i < a.rows; i++)
		{
			for (j = 0; j < a.cols; j++)
			{
				b.at<Vec3b>(i, j)[0] = a.at<Vec3b>(i, a.cols - 1 - j)[0];
				b.at<Vec3b>(i, j)[1] = a.at<Vec3b>(i, a.cols - 1 - j)[1];
				b.at<Vec3b>(i, j)[2] = a.at<Vec3b>(i, a.cols - 1 - j)[2];
			}
		}

		Canny(b, c, 110, 140, 3);

		imshow("Vid", c);

		int z = waitKey(1);
		if (z == (int) 'e')
			break;
	}
	return 0;
}