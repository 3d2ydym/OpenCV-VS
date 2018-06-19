#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

//��Ĥ����
int main(int argc, char** argv)
{
	Mat src, dst;
	src = imread("C:/Users/yefci/Pictures/girl.png");
	if (!src.data) {
		cout << "could not load image..." << endl;
		return -1;
	}

	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	double t = getTickCount();
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dst, src.depth(), kernel);//���롢�����ԭͼ��ȡ���Ĥ
	double timeconsume = (getTickCount() - t) / getTickFrequency();
	cout << "time consume: " << timeconsume;

	namedWindow("output image", CV_WINDOW_AUTOSIZE);
	imshow("output image", dst);

	waitKey(0);
	return 0;
}