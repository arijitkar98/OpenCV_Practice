#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "opencv2/core/core.hpp"
#include <vector>
#include <stack>

using namespace cv;
using namespace std;

struct point{
	int y, x;
};

int isValid(Mat img, int x, int y)
{
	if (x < 0 || y < 0 || x >= img.rows || y >= img.cols)
		return 0;
	else return 1;
}

Mat img = imread("C:\\Users\\ariji\\Desktop\\Extra\\dfs_path.jpg", 0);

Mat visited(img.rows, img.cols, CV_8UC1, Scalar(255));

stack<point> S;

void DFS_PATH(point start, point end)
{
	int i, j, k, l;
	int m, n;

	point current;

	S.push(start);

	imshow("Original", img);
	/*imshow("Binary", visited);
	waitKey(1);*/

	//	printf("(%d,%d) \n", start.y, start.x);

	if (start.y != end.y && start.x != end.x)
	{

		i = start.y;
		j = start.x;

		visited.at<uchar>(i, j) = (0);

		for (k = i - 1; k < i + 2; k++)
		{
			for (l = j - 1; l < j + 2; l++)
			{
				if (isValid(img, k, l))
				{
					//					printf("(%d,%d) \n", k, l);
					if ((visited.at<uchar>(k, l) == 255) && (img.at<uchar>(k, l) == 255))
					{
						//printf("(%d,%d) \n", k, l);
						DFS_PATH({ k, l }, end);
					}
				}
			}
		}

		current = S.top();

		i = current.y;
		j = current.x;

		m = 0; n = 0;

		for (k = i - 1; k < i + 2; k++)
		{
			for (l = j - 1; l < l + 2; l++)
			{
				if (isValid(img, k, l))
				{
					if ((visited.at<uchar>(k, l) == 255 / 2) && (img.at<uchar>(k, l) == 255))
					{
						m++;
					}
					n++;
				}
			}
		}
		if (m == n)
		{
			S.pop();
		}
	}
}


int main()
{
	point start, end, temp;
	Mat final(img.rows, img.cols, CV_8UC1, Scalar(0));

	start.y = 0;
	start.x = 0;

	end.y = img.rows - 1;
	end.x = img.cols - 1;

	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Binary", WINDOW_AUTOSIZE);

	DFS_PATH(start, end);

	printf("\n\n\n Path is :- \n\n\n");

	while (!S.empty())
	{
		temp = S.top();

		final.at<uchar>(temp.y, temp.x) = 0;
		imshow("Binary", final);
		waitKey(1);

		printf("(%d,%d)", temp.x, temp.y);

		S.pop();
	}

	//	waitKey(0);

	return 0;
}