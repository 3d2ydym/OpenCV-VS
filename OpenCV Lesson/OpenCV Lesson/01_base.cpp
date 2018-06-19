#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat srcImg = imread("C:/Users/yefci/Pictures/aditya-vyas-542857-unsplash.jpg");
	if (srcImg.empty()) {
		cout << "could not load image..." << endl;
		return -1;
	}
	namedWindow("test opencv setup", CV_WINDOW_AUTOSIZE);//����һ�������Զ����ٵĴ��ڣ����ڴ�С�Զ�
	imshow("test opencv setup", srcImg);

	namedWindow("output windows", CV_WINDOW_AUTOSIZE);
	Mat dstImg;
	cvtColor(srcImg, dstImg, CV_BGR2HLS);
	imshow("output windows", dstImg);

	imwrite("C:/Users/yefci/Desktop/1.jpg", dstImg);
	waitKey(0);
	return 0;
}