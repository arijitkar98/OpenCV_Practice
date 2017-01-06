#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j;

	Mat a(400, 400, CV_8UC3, Scalar(255, 0, 0));

	for (i = 0; i < 400; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			a.at<Vec3b>(i, j)[0] = 0;
			a.at<Vec3b>(i, j)[1] = 255;
		}
	}

	namedWindow("abc", WINDOW_AUTOSIZE);

	imshow("abc", a);
	waitKey(0);

	return 0;
}


