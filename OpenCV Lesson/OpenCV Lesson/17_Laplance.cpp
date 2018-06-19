#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int agrc, char** agrv)
{
	Mat src, dst;
	src = imread("C:/Users/yefci/Desktop/lab/paste.png");
	if (!src.data) {
		cout << "could not load image" << endl;
		return -1;
	}
	char inWin[] = "input iamge";
	namedWindow(inWin, 1);
	imshow(inWin, src);

	Mat grayImg, edgeImg;
	GaussianBlur(src, dst, Size(3, 3), 0, 0);
	cvtColor(dst, grayImg, CV_BGR2GRAY);

	Laplacian(grayImg, edgeImg, CV_16S, 3);
	imshow("Laplace����(�и�ֵ)", edgeImg);
	convertScaleAbs(edgeImg, edgeImg);//��ֵ����
	imshow("Laplace����", edgeImg);

	threshold(edgeImg, edgeImg, 0, 255, THRESH_OTSU | THRESH_BINARY);
	imshow("Laplace+��ֵ����", edgeImg);

	waitKey(0);
	return 0;
}