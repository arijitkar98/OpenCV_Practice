#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <stack>

using namespace cv;
using namespace std;

Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\binary2.png", 0);

Mat visited(img.rows, img.cols, CV_8UC3, Scalar(255, 255, 255));

struct point{
	int x, y;
};

int isValid(Mat img, int x, int y)
{
	if (x < 0 || y < 0 || x >= img.rows || y >= img.cols)
		return 0;
	else return 1;
}

void DFS(int i, int j)
{
	int k, l; int cnt = 1;

	point start, current, temp;
	start.x = i;
	start.y = j;

	stack<point> S;

	S.push(start);
	visited.at<Vec3b>(i, j)[2] = (255 / (cnt + 1));

	while (!S.empty())
	{
		current = S.top();
		S.pop();

		for (k = current.x - 1; k < current.x + 2; k++)
		{
			for (l = current.y - 1; l < current.y + 2; l++)
			{
				if (isValid(img, k, l))
				{
					if ((visited.at<Vec3b>(k, l)[0] == 255) && (visited.at<Vec3b>(k, l)[1] == 255) && (visited.at<Vec3b>(k, l)[2] == 255) && (img.at<uchar>(k, l) == 255))
					{
						temp.x = k; temp.y = l;
						S.push(temp);
						visited.at<Vec3b>(k, l)[2] = 255 / (cnt + 1);
					}
				}
			}
		}
	}
}

void Callbackfunc(int Event, int y, int x, int flags, void *userdata)
{
	if (Event == EVENT_LBUTTONDOWN)
	{
		DFS(x, y);

	}
}

int main()
{
	int i, j, z;

	namedWindow("abc", WINDOW_AUTOSIZE);

	namedWindow("def", WINDOW_AUTOSIZE);

	for (i = 0; i < img.rows; i++)
	{
		for (j = 0; j < img.cols; j++)
		{
			if (img.at<uchar>(i, j) == 0)
			{
				visited.at<Vec3b>(i, j)[0] = 0;
				visited.at<Vec3b>(i, j)[1] = 0;
				visited.at<Vec3b>(i, j)[2] = 0;
			}
			else
			{
				visited.at<Vec3b>(i, j)[0] = 255;
				visited.at<Vec3b>(i, j)[1] = 255;
				visited.at<Vec3b>(i, j)[2] = 255;
			}
		}
	}

	while (1)
	{
		imshow("abc", img);

		imshow("def", visited);

		setMouseCallback("abc", Callbackfunc, NULL);

		z = waitKey(50);
		if (z == (int)'e')
			break;
	}
	return 0;
}


