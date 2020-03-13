// Caphudutu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap(0);
    double scale = 0.5;

    double i_minH = 0;
    double i_maxH = 20;
    double i_minS = 43;
    double i_maxS = 255;
    double i_minV = 55;
    double i_maxV = 255;

    while (1)
    {
        Mat frame;
        Mat hsvMat;
        Mat detectMat;

        cap >> frame;
        Size ResImagSiz = Size(frame.cols * scale, frame.rows * scale);
        Mat rFrame = Mat(ResImagSiz, frame.type());
        resize(frame, rFrame, ResImagSiz, INTER_LINEAR);

        cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);

        rFrame.copyTo(detectMat);

        cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);

        imshow("whie:in the range", detectMat);
        imshow("frame", rFrame);

        waitKey(30);
    }
  
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
