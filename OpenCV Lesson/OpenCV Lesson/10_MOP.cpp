#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src, dst;
int element_size = 3;//Ĭ������/��ʴ�̶�
int max_size = 21;
void CallBack_Demo(int, void*);//�ص���������һ��ͨ������ָ����õĺ�����

int main(int argc, char** argv)
{
	src = imread("C:/Users/yefci/Desktop/lab/Snipaste_c.png");
	if (!src.data) {
		printf("could not load image");
		return -1;
	}
	char inTitle[] = "input image";
	namedWindow(inTitle, 1);
	imshow(inTitle, src);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(13, 13), Point(-1, -1));
	morphologyEx(src, dst, CV_MOP_OPEN, kernel);
	imshow("open", dst);
	morphologyEx(src, dst, CV_MOP_CLOSE, kernel);
	imshow("close", dst);
	morphologyEx(src, dst, CV_MOP_GRADIENT, kernel);
	imshow("gradient", dst);
	morphologyEx(src, dst, CV_MOP_TOPHAT, kernel);
	imshow("tophat ԭͼ�뿪��ֵ", dst);
	morphologyEx(src, dst, CV_MOP_BLACKHAT, kernel);
	imshow("blachhat", dst);

	waitKey(0);
	return 0;
}