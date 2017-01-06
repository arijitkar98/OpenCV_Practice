#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <algorithm>
#include <math.h>


using namespace cv;
using namespace std;

int main()
{
	int x = 0, y = 0, n;

	Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\y.png", 1);

	Mat img1;

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Canny", WINDOW_AUTOSIZE);

	createTrackbar("Low_Th", "Canny", &x, 1000);
	createTrackbar("High_Th", "Canny", &y, 1000);

	while (1)
	{
		Canny(img, img1, x, y, 3);

		imshow("Original", img);
		imshow("Canny", img1);

		n = waitKey(50);
		if (n == (int)'e')
			break;
	}
	return 0;
}


