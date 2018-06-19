/*
��ͼ����ԣ���Ƶ����չ��ͼ��ϸ�ڣ����Ե�ͨ�˲���ͼ��ģ������Ϊ��˹ģ����
��ԣ���ͨ�˲��˵���Ƶ���Ӷ���ͼ������񻯣�ͼ�������������Ϊ��˹�˲���
��˹ģ�����ø�˹��ͨ�˲�����
��˹�˲���ָ�ø�˹������Ϊ�˲������Ĳ�����
*/

#include<iostream>
#include<stdio.h>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//����ȫ�ֱ���
Mat src, dst;

//����켣�����ֵ����
const int g_nKwidthTrackBarMaxValue = 9;
const int g_nKheightTrackBarMaxValue = 9;
const int g_nsigmaXTrackBarMaxValue = 9;
const int g_nsigmaYTrackBarMaxValue = 9;

//����켣����ʼֵ
int g_nKwidthTrackBarValue = 1;
int g_nKheightTrackBarValue = 1;
int g_nsigmaXTrackBarValue = 1;
int g_nsigmaYTrackBarValue = 1;

int g_kernelWidthValue;
int g_kernelHeightValue;

void on_GaussianBlurTrackBar(int, void*);//����ص�����

int main()
{
	src = imread("C:/Users/yefci/Desktop/lab/2.jpg");

	//�ж�ͼƬ�Ƿ���سɹ�
	if (!src.data)
	{
		cout << "ͼ�����ʧ�ܣ�" << endl;
		return -1;
	}
	else
		cout << "ͼ����سɹ�!" << endl;

	namedWindow("ԭͼ", WINDOW_NORMAL);//�ɵ���ͼ���С
	imshow("ԭͼ", src);

	namedWindow("��˹�˲�ͼ��", WINDOW_NORMAL);

	//����ÿ���켣����
	char widthTrackBarName[20];
	printf(widthTrackBarName, "width %d", g_nKwidthTrackBarMaxValue);
	char heightTrackBarName[20];
	printf(heightTrackBarName, "height %d", g_nKheightTrackBarMaxValue);
	char sigmaXTrackBarName[20];
	printf(sigmaXTrackBarName, "sigX %d", g_nsigmaXTrackBarMaxValue);
	char sigmaYTrackBarName[20];
	printf(sigmaYTrackBarName, "sigY %d", g_nsigmaYTrackBarMaxValue);

	//�����켣��
	createTrackbar(widthTrackBarName, "��˹�˲�ͼ��", &g_nKwidthTrackBarValue, g_nKwidthTrackBarMaxValue, on_GaussianBlurTrackBar);
	createTrackbar(heightTrackBarName, "��˹�˲�ͼ��", &g_nKheightTrackBarValue, g_nKheightTrackBarMaxValue, on_GaussianBlurTrackBar);
	createTrackbar(sigmaXTrackBarName, "��˹�˲�ͼ��", &g_nsigmaXTrackBarValue, g_nsigmaXTrackBarMaxValue, on_GaussianBlurTrackBar);
	createTrackbar(sigmaYTrackBarName, "��˹�˲�ͼ��", &g_nsigmaYTrackBarValue, g_nsigmaYTrackBarMaxValue, on_GaussianBlurTrackBar);


	waitKey(0);
	return 0;
}

void on_GaussianBlurTrackBar(int, void*)
{
	//���������width��height���¼���ksize.width��ksize.height
	g_kernelWidthValue = g_nKwidthTrackBarValue * 2 + 1;
	g_kernelHeightValue = g_nKheightTrackBarValue * 2 + 1;

	//��˹�˲�
	GaussianBlur(src, dst, Size(g_kernelWidthValue, g_kernelHeightValue), g_nsigmaXTrackBarValue, g_nsigmaYTrackBarValue);

	imshow("��˹�˲�ͼ��", dst);
}