#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j;

	VideoCapture vid("C:\\Users\\ariji\\Desktop\\Extra\\Minuscule - S01E01 - The Ladybug [hjpotter92].mp4");

	Mat temp, a;

	vid.read(temp);

	a = temp.clone();
	Mat b(a.rows, 2 * a.cols, CV_8UC1, Scalar(255));

	namedWindow("Vid", WINDOW_AUTOSIZE);
	/*
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
	*/

	i = vid.get(CV_CAP_PROP_FRAME_COUNT);
	j = vid.get(CV_CAP_PROP_POS_FRAMES);

	for (;;)
	{
		i = vid.get(CV_CAP_PROP_FRAME_COUNT);
		j = vid.get(CV_CAP_PROP_POS_FRAMES);

		imshow("Vid", b);

		int z = waitKey(1);
		if (z == (int) 'e')
			break;
	}
	return 0;
}