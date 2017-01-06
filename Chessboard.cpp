#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int i, j, k, l, m, n, o, p;
	Mat a(800, 800, CV_8UC3, Scalar(0, 0, 0));

	o = 0; p = 0;
	for (n = 0; n < 8; n++)
	{
		for (i = 0; i < 100; i++)
		{
			l = 0; m = p;
			for (j = 0; j < 8; j++)
			{
				for (k = 0; k < 100; k++)
				{

					a.at<Vec3b>(i + o, k + l)[0] = m;
					a.at<Vec3b>(i + o, k + l)[1] = m;
					a.at<Vec3b>(i + o, k + l)[2] = m;
				}
				l += 100;
				if (m == 0)
					m = 255;
				else if (m == 255)
					m = 0;
			}
		}
		o += 100;
		if (p == 0)
			p = 255;
		else if (p == 255)
			p = 0;
	}
	namedWindow("def", WINDOW_AUTOSIZE);

	imshow("def", a);
	waitKey(0);

	return 0;
}