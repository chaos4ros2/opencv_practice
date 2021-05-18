// image_proc_sl.cpp
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
 
extern "C" int ImageProc()
{
    cv::Mat img;
    img = cv::imread("dog.jpg", cv::IMREAD_COLOR);
    cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
    cv::imshow("image", img);
 
    cv::Mat gray_img;
    gray_img = cv::imread("dog.jpg", cv::IMREAD_GRAYSCALE);
    cv::namedWindow("Gray_image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Gray_image", gray_img);
    
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
