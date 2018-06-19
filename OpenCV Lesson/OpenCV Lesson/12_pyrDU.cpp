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
	//���������ϲ���
	pyrDown(src, dst, Size(src.cols / 2, src.rows / 2));
	imshow("������", dst);
	pyrUp(src, dst, Size(src.cols * 2, src.rows * 2));
	imshow("�ϲ���", dst);

	//DOG
	Mat grayImg, g1, g2;
	cvtColor(src, grayImg, CV_BGR2GRAY);//ת�Ҷ�ͼ
	GaussianBlur(src, g1, Size(3, 3), 0, 0);//��һ���˹
	GaussianBlur(g1, g2, Size(3, 3), 0, 0);//�ڶ����˹
	subtract(g1, g2, src, Mat());
	
	//��һ����ʾ
	normalize(src, src, 255, 0, NORM_MINMAX);
	imshow("DOG Image", src);

	waitKey(0);
	return 0;
}