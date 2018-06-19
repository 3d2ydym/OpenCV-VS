#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src, dst;

int main(int agrc, char* agrv)
{
	src = imread("C:/Users/yefci/Desktop/lab/anni.jpg");
	if (!src.data) {
		cout << "could not load image" << endl;
		return -1;
	}
	//ͼ����ʾ
	char srcImg[] = "input image";
	namedWindow(srcImg, 1);
	imshow(srcImg, src);
	
	//ͼ��ʴ
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	erode(src, dst, element);
	imshow("erode image", dst);

	//ͼ��ģ��
	blur(src, dst, Size(3, 3), Point(-1, -1), 4);
	imshow("blur image", dst);

	//canny��Ե���
	cvtColor(src, dst, CV_BGR2GRAY);//1 ��ת�Ҷ�
	blur(dst, dst, Size(3, 3));//2 �ٽ��루Ĭ��ֵ��ʡ�ԣ�
	Canny(dst, dst, 3, 9, 3);//3 ��Ե���
	imshow("canny image", dst);
	/*
	//��ȡ��������Ƶ
	VideoCapture capture("C:/Users/yefci/Desktop/lab/1.avi");//ʵ����һ��VideoCapture��Ķ��󣬶�ȡ��Ƶ
	while (true)
	{
		Mat frame;//����һ��Mat���������ڴ洢ÿһ֡��ͼ��
		capture >> frame;  //��ȡ��ǰ֡

		//����Ƶ������ɣ��˳�ѭ��
		if (frame.empty())
		{
			break;
		}

		imshow("��ȡ��Ƶ", frame);  //��ʾ��ǰ֡
		waitKey(30);  //��ʱ30ms
	}*/

	//��������ͷ�ɼ�ͼ��
	VideoCapture capture2(0);//������ͷ������Ƶ
	//ѭ����ʾÿһ֡
	while (1)
	{
		Mat frame;  //����һ��Mat���������ڴ洢ÿһ֡��ͼ��
		capture2 >> frame;  //��ȡ��ǰ֡
		imshow("����ͷ��Ƶ", frame);  //��ʾ��ǰ֡
		waitKey(30);  //��ʱ30ms
	}
	waitKey(0);
	return 0;
}