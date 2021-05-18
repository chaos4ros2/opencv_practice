// opencv_test.cpp
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
 
int main(){
    cv::Mat img;
    img = cv::imread("dog.jpg", cv::IMREAD_COLOR);
    cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
    cv::imshow("image", img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
