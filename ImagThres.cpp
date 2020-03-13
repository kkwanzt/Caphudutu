#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
	cv::Mat result,resultadp;
	cv::Mat srcImage= imread("D:\\opencv\\myproject\\timg.jpg", 0);
	threshold(srcImage, result, 100, 255, THRESH_BINARY);
	adaptiveThreshold(srcImage, resultadp, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 15, 10);
	namedWindow("resultadp");
	cv::imshow("output image", result);
	cv::imshow("resultadp", resultadp);
	waitKey(0);
	return 0;
}