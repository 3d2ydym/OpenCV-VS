#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat src, dst;

int main(int agrc, char** argv)
{
	src = imread("C:/Users/yefci/Desktop/lab/ling.jpg");
	if (!src.data) {
		cout << "loading image failed" << endl;
		return -1;
	}

	char inWin[] = "input window";
	namedWindow(inWin, 1);
	imshow(inWin, src);

	int top = (int)(0.05*src.rows);//��Ե�ľ���
	int bottom = top;
	int left = (int)(0.05*src.cols);
	int right = left;
	RNG rng(12345);
	int borderType = BORDER_DEFAULT;

	int c = 0;
	while (true) {
		c = waitKey(500);
		//ESC�˳�
		if ((char)c == 27) {
			break;
		}
		//�������ֱ�Ե������
		if ((char)c == 'r') {
			borderType = BORDER_REFLECT;//����
		}
		else if ((char)c == 'w') {
			borderType = BORDER_WRAP;//����
		}
		else if ((char)c == 'c') {
			borderType = BORDER_CONSTANT;//�����ɫ
		}
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));//�����������ɫ
		copyMakeBorder(src, dst, top, bottom, left, right, borderType, color);
		imshow("boderImage", dst);
	}

	GaussianBlur(src, dst, Size(9, 9), 0, 0, BORDER_DEFAULT);
	imshow("Gaussian_D", dst);
	GaussianBlur(src, dst, Size(9, 9), 0, 0, BORDER_REFLECT);
	imshow("Gaussian_R", dst);
	GaussianBlur(src, dst, Size(9, 9), 0, 0, BORDER_WRAP);
	imshow("Gaussian_W", dst);
	GaussianBlur(src, dst, Size(9, 9), 0, 0, BORDER_CONSTANT);
	imshow("Gaussian_C", dst);

	waitKey(0);
	return 0;
}