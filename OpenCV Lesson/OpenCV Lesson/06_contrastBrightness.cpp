#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

double alpha; /** < Simple contrast control */
int beta;     /** < Simple brightness control */

int main(int argc, char** argv)
{
	Mat src, dst;
	// ����ͼ��
	src = imread("C:/Users/yefci/Desktop/lab/qrcode2.jpg");

	if (!src.data) {//���ͼƬ�Ƿ�Ϊ��
		printf("Could not load Logo image 1...");
		return -1;
	}

	// Ŀ��ͼ��ռ�Ԥ����
	dst = Mat::zeros(src.size(), src.type());

	/// �����ʼ��ֵ
	cout << " Basic Linear Transforms " << endl;
	cout << "-------------------------" << endl;
	cout << " *Enter the alpha value [1.0-3.0]: ";
	cin >> alpha;
	cout << " *Enter the beta value [0-100]: ";
	cin >> beta;

	//Mat m1;
	//src.convertTo(m1, CV_32F);//���������ˣ�����Ϳ�����Vec3f ��

	// ִ�б任 dst(i,j) = alpha * src(i,j) + beta
	for (int row = 0; row < src.rows; row++) 
	{
		for (int col = 0; col < src.cols; col++) 
		{
			if (src.channels() == 3) 
			{
				for (int c = 0; c < 3; c++)
				{
					float v = src.at<Vec3b>(row, col)[c];//��������ͼƬ��8U���������ﲻ����Vec3f
					dst.at<Vec3b>(row, col)[c] = saturate_cast<uchar>(v*alpha + beta);
				}
			}
			else if (src.channels() == 1) 
			{
				float v = src.at<uchar>(row, col);//���� at()��ʵ�ֶ�ȡ�����е�ĳ������
				dst.at<uchar>(row, col) = saturate_cast<uchar>(v*alpha + beta);
			}
		}
	}
	// ������ʾ����
	char srcName[] = "input image";
	char output[] = "contrast and brightness change demo";
	namedWindow(srcName, CV_WINDOW_AUTOSIZE);
	namedWindow(output, 1);
	// ��ʾͼ��
	imshow(srcName, src);
	imshow(output, dst);
	// �ȴ������¼�
	waitKey(0);
	return 0;
}