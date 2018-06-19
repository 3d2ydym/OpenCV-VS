#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src, dst;

int main(int argc, char** argv)
{
	src = imread("C:/Users/yefci/Desktop/lab/lines.png");
	if (!src.data) {
		printf("could not load image");
		return -1;
	}
	char inTitle[] = "input image";
	namedWindow(inTitle, 1);
	imshow(inTitle, src);

	Mat grayImg;
	cvtColor(src, grayImg, CV_BGR2GRAY);
	imshow("gray", grayImg);

	Mat binImg;
	adaptiveThreshold(~grayImg, binImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	//ע��˴� ~ ��Ϊȡ�����ȷ�ת��ɫ������ֵ���������кõ�Ч��
	imshow("binary", binImg);

	//ˮƽ��
	Mat xline = getStructuringElement(MORPH_RECT, Size(src.cols / 16, 1), Point(-1, -1));
	//��ֱ��
	Mat yline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 16), Point(-1, -1));
	//����
	Mat rect = getStructuringElement(MORPH_RECT, Size(4,4));//����size���Ը���Ч��

	morphologyEx(binImg, dst, CV_MOP_OPEN, xline);
	bitwise_not(dst, dst);//��ת������ɫ
	blur(dst, dst, Size(3, 3), Point(-1, -1));//ģ��������ʹͼ���Բ�󣬴Ӷ�����覴�
	imshow("xline", dst);
	
	morphologyEx(binImg, dst, CV_MOP_OPEN, yline);
	bitwise_not(dst, dst);
	blur(dst, dst, Size(3, 3), Point(-1, -1));
	imshow("yline", dst);

	morphologyEx(binImg, dst, CV_MOP_OPEN, rect);
	bitwise_not(dst, dst);
	imshow("rectangle", dst);//���մﵽ��ֻ������ĸ��Ч��
	//����ʵ�ָ�����֤������ĸ����ȡ


	waitKey(0);
	return 0;
}