#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat bgImg;
const char* dravdemo_win = "draw shapes and text demo";//��仰�����
void MyLines();
void MyRectangle();
void MyEllipse();
void MyCircle();
void MyPloygon();
void RandomLineDemo();
int main(int argc, char** argv) 
{
	bgImg = imread("C:/Users/yefci/Pictures/Camera Roll/������.jpg");
	if (!bgImg.data) {
		printf("could not load image");
		return -1;
	}

	//������ò���
	/*MyLines();
	MyRectangle();//�ǵ�Ҫ��ǰ�������º�������Ȼ������Ҳ�����ʶ������
	MyEllipse();
	MyCircle();
	MyPloygon();
	
	putText(bgImg, "Hello OpenCV", Point(300, 200), CV_FONT_BLACK, 2.0, Scalar(50, 60, 255), 1, 8);

	namedWindow("lines", 1);
	imshow("lines", bgImg);*/

	RandomLineDemo();

	waitKey(0);
	return 0;
}

//�����岿��
//����
void MyLines()
{
	Point p1 = Point(20, 30);//һ�ֶ��巽ʽ
	Point p2;
	p2.x = 90;
	p2.y = 90;//��һ�ֶ��巽ʽ
	Scalar color = Scalar(0, 0, 255);//����color���������ڱ�ʾ��ɫ
	line(bgImg, p1, p2, color, 9, LINE_8);//�߿�Ϊ9
}
//������
void MyRectangle()
{
	Rect rect = Rect(200, 100, 90, 90);//x,y,width,height
	Scalar color = Scalar(255, 0, 0);//Blue
	rectangle(bgImg, rect, color, 8, LINE_8);
}
//����Բ
void MyEllipse()
{
	Point Epoint = Point(bgImg.cols / 2, bgImg.rows / 2);//Բ��x,y
	Size Esize = Size(bgImg.cols / 4, bgImg.rows / 8);//x,y��뾶
	Scalar color = Scalar(0, 255, 0);
	int degree = 90;//Բ������ֵĽǶ�
	int starD = 0;//Բ����ʼλ�ö���
	int endD = 360;//Բ����ֹλ�ö���
	int Lwidth = 2;//�߿�
	ellipse(bgImg, Epoint, Esize, degree, starD, endD, color, Lwidth, LINE_8);
}
//��Բ
void MyCircle()
{
	Point center = Point(bgImg.cols / 2, bgImg.rows / 2);//Բ��x,y
	int radius = 150;//�뾶
	Scalar color = Scalar(0, 255, 255);
	circle(bgImg, center, radius, color, 2, 8);//ע�������LINE_8����ֱ��д��8
}
//�������
void MyPloygon()
{
	Point pts[1][6];
	pts[0][0] = Point(130, 122);
	pts[0][1] = Point(146, 122);
	pts[0][2] = Point(146, 145);
	pts[0][3] = Point(125, 146);
	pts[0][4] = Point(126, 139);
	pts[0][5] = Point(120, 131);

	const Point* ppts[1] = { pts[0] };//����һ��ָ�룬ָ���ά����ĵ�0��λ��
	int npt[] = { 6 };//��������6����
	Scalar color = Scalar(99, 100, 255);

	fillPoly(bgImg, ppts, npt, 1, color, 8);//�����1����ָ����������
}
//�������
void RandomLineDemo()
{
	RNG rng(12345);
	Point pt1;
	Point pt2;
	Mat bg = Mat::zeros(bgImg.size(), bgImg.type());
	namedWindow("random line", 1);
	for (int i = 0; i < 10000; i++) {
		pt1.x = rng.uniform(0, bgImg.cols);//�������
		pt1.y = rng.uniform(0, bgImg.cols);
		pt2.x = rng.uniform(0, bgImg.cols);
		pt2.y = rng.uniform(0, bgImg.cols);
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		if (waitKey(50) > 0) {//�ȴ�50s
			break;
		}
		line(bg, pt1, pt2, color, 1, 8);
		imshow("random line", bg);
	}
}
