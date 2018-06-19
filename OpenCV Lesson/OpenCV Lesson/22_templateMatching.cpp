#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

Mat src, temp, dst;
int match_method = CV_TM_SQDIFF;//Ĭ�ϵ�ƥ�䷽��
int max_track = 5;//�켣����������Ϊ5����Ϊ�ܹ�6�ַ���
const char* srcImg = "input image";
const char* matImg = "template match image";
const char* dstImg = "output image";
void Match_Demo(int, void*);

int main(int agrc, char** agrv)
{
	src = imread("C:/Users/yefci/Desktop/lab/����.jpg");//�����ͼ��
	temp = imread("C:/Users/yefci/Desktop/lab/anface.jpg");//ģ��ͼ��
	if (src.empty() || temp.empty()) {
		cout << "could not load image" << endl;
		return -1;
	}
	namedWindow(srcImg, 1);
	namedWindow(matImg, 1);
	namedWindow(dstImg, 1);
	imshow(srcImg, temp);

	const char* tBar = "Match Algo Type:";
	createTrackbar(tBar, dstImg, &match_method, max_track, Match_Demo);
	Match_Demo(0, 0);


	waitKey(0);
	return 0;
}

void Match_Demo(int, void*)
{
	int width = src.cols - temp.cols + 1;
	int height = src.rows - temp.rows + 1;
	Mat result(width, height, CV_32FC1); 

	matchTemplate(src, temp, result, match_method, Mat());
	normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

	Point minLoc, temLoc, maxLoc;
	double min, max;
	src.copyTo(dst);
	minMaxLoc(result, &min, &max, &minLoc, &maxLoc, Mat());
	if (match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED) {
		temLoc = minLoc;
	}
	else {
		temLoc = maxLoc;
	}
	//���ƾ���
	rectangle(dst, Rect(temLoc.x, temLoc.y, temp.cols, temp.rows), Scalar(0, 0, 255), 2, 8);
	rectangle(result, Rect(temLoc.x, temLoc.y, temp.cols, temp.rows), Scalar(0, 0, 255), 2, 8);

	imshow(dstImg, dst);
	imshow(matImg, result);
}