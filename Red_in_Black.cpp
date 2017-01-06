#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j;

	Mat a(400, 400, CV_8UC3, Scalar(0, 0, 0));

	for (i = 100; i<300; i++)
	{
		for (j = 100; j<300; j++)
			a.at<Vec3b>(i, j)[2] = 255;
	}

	namedWindow("abc", WINDOW_AUTOSIZE);

	imshow("abc", a);
	waitKey(0);

	return 0;
}


