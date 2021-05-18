# include <opencv2/opencv.hpp>
# pragma comment(lib, "opencv_world400.lib")
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    try {
        if (argc < 3)
            throw "few parameter, e.g. <file name> <flip code>.";

        Mat src = imread(argv[1]);
        int flipCode = stoi(argv[2]);

        if (src.empty()) 
            throw "faild open file.";

        Mat dst;
        flip(src, dst, flipCode);

        imshow("src", src);
        imshow("dst", dst);

        waitKey(0);
    } catch (const char* str) {
        cerr << str << endl;
    }
    return 0;
}