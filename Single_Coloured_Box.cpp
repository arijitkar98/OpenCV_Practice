#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat a(400, 400, CV_8UC3, Scalar(127, 127, 255));

	namedWindow("abc", WINDOW_AUTOSIZE);

	imshow("abc", a);
	waitKey(0);

	return 0;
}


