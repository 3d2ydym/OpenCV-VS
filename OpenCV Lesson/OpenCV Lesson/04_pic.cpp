#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat src, src_gray;
	src = imread("C:/Users/yefci/Pictures/Sni.png");
	if (src.empty()) {
		cout << "could not load image..." << endl;
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	cvtColor(src, src_gray, CV_BGR2GRAY);
	namedWindow("gray", CV_WINDOW_AUTOSIZE);
	imshow("gray", src_gray);

	int height = src_gray.rows;
	int width = src_gray.cols;
	//��ͨ��
	/*for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			int gray = src_gray.at<uchar>(row, col);//��ȡͼ���е�ÿ������
			src_gray.at<uchar>(row, col) = 255 - gray;//��ԭλ�õ����ؽ��лҶȷ���
		}
	}
	imshow("�Ҷȷ���", src_gray);*/
	//��ͨ��
	Mat dst,gray_try1,gray_try2;
	dst.create(src.size(), src.type());
	height = dst.rows;
	width = dst.cols;
	int nc = dst.channels();//ͨ����
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (nc == 1) {//��ͨ�����
				int gray = src_gray.at<uchar>(row, col);//��ȡͼ���е�ÿ������
				src_gray.at<uchar>(row, col) = 255 - gray;//��ԭλ�õ����ؽ��лҶȷ���
			}
			else if (nc == 3) {//3ͨ�����Է���
				int b = src.at<Vec3b>(row, col)[0];
				int g = src.at<Vec3b>(row, col)[1];
				int r = src.at<Vec3b>(row, col)[2];
				dst.at<Vec3b>(row, col)[0] = 255 - b;
				dst.at<Vec3b>(row, col)[1] = 255 - g;
				dst.at<Vec3b>(row, col)[2] = 255 - r;
				src_gray.copyTo(gray_try1);
				src_gray.copyTo(gray_try2);
				gray_try1.at<uchar>(row, col) = max(r, max(b, g));//
				gray_try2.at<uchar>(row, col) = min(r, min(b, g));//
			}
		}
	}
	imshow("�Ҷ���ǿ", gray_try1);
	imshow("�Ҷȼ���", gray_try2);
	imshow("��ɫ����", dst);
	bitwise_not(src, dst);//����APIʵ�ֲ�ɫ����
	imshow("APIʵ��", dst);

	waitKey(0);
	return 0;
}