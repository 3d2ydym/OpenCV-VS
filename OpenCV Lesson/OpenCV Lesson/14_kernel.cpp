#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat src, dst;

int main(int argc, char** argv)
{
	src = imread("C:/Users/yefci/Desktop/lab/tiya.png");
	if (!src.data) {
		printf("could not load image");
		return -1;
	}

	char inputWin[] = "input image";
	namedWindow(inputWin, 1);
	imshow(inputWin, src);

	//Robert X����
	Mat robert_x = (Mat_<int>(2, 2) << 1, 0, 0, -1);
	filter2D(src, dst, -1, robert_x, Point(-1, -1), 0.0);
	imshow("Robert X", dst);
	//Robert Y����
	Mat robert_y = (Mat_<int>(2, 2) << 0, 1, -1, 0);
	filter2D(src, dst, -1, robert_y, Point(-1, -1), 0.0);
	imshow("Robert Y", dst);

	//Sobel X����
	Mat sobel_x = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
	filter2D(src, dst, -1, sobel_x, Point(-1, -1), 0.0);
	imshow("Sobel X", dst);
	//Sobel Y����
	Mat sobel_y = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	filter2D(src, dst, -1, sobel_y, Point(-1, -1), 0.0);
	imshow("Sobel Y", dst);

	//������˹
	Mat lap = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	filter2D(src, dst, -1, lap, Point(-1, -1), 0.0);
	imshow("Laplacian", dst);

	//�Զ�����-��ģ��
	int c = 0;
	int index = 0;
	int ksize = 3;
	while (true) {
		c = waitKey(500);
		if ((char)c == 27) {//waitKey(27) ��esc
			break;
		}
		ksize = 1 + (index % 5) * 2 + 1;//�ⲿ�����Ǹ���� ģ���̶�
		Mat kernel = Mat::ones(Size(ksize, ksize), CV_32F) / (float)(ksize*ksize);
		filter2D(src, dst, -1, kernel, Point(-1, -1));
		index++;
		imshow("define kernel", dst);
	}

	waitKey(0);
	return 0;
}