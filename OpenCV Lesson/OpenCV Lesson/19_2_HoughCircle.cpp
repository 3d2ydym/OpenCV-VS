#include<iostream>
#include<opencv2/opencv.hpp>
#include<math.h>

using namespace std;
using namespace cv;

int main(int agrc, char** agrv)
{
	Mat src, grayImg, dst;
	src = imread("C:/Users/yefci/Desktop/lab/mix.png");
	if (!src.data) {
		cout << "could not load image" << endl;
		return -1;
	}
	char inWin[] = "input iamge";
	namedWindow(inWin, 1);
	imshow(inWin, src);

	Mat mediaImg;
	medianBlur(src, mediaImg, 7);//��ֵ�˲�
	cvtColor(mediaImg, mediaImg, CV_BGR2GRAY);//תΪ�Ҷ�

	Canny(src, dst, 100, 200);
	imshow("Canny", dst);

	//����Բ���
	vector<Vec3f>pcircles;//����Բ
	HoughCircles(mediaImg, pcircles, CV_HOUGH_GRADIENT, 1, 10, 100, 18, 5, 50);//�û���任��ÿ��ܵ�Բ������(0,1,2)��ʽ
	src.copyTo(dst);//��ԭͼ�񿽱���Ŀ��ͼ��
	for (size_t i = 0; i < pcircles.size(); i++) {
		Vec3f cc = pcircles[i];//circlr center����
		circle(dst, Point(cc[0], cc[1]), cc[2], Scalar(1, 1, 255), 2, LINE_AA);//����Բ
		circle(dst, Point(cc[0], cc[1]), 1, Scalar(1, 1, 255), 0.5, LINE_AA);//����Բ��
	}
	imshow("Hough Circle", dst);

	waitKey(0);
	return 0;
}