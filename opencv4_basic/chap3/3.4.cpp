# include <opencv2/opencv.hpp>
# include <opencv2/core.hpp>
# include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
# pragma comment(lib, "opencv_world400.lib")

using namespace cv;
using namespace std;

static void
add1mat(const Mat& mat) {
    Mat dst = mat + 1;
    cout << "dst=" << dst << endl << endl;
}

static void
add1array(const InputArray inputSrc_) {
    Mat src = inputSrc_.getMat();
    Mat dst = src + 1;
    cout << "dst=" << dst << endl << endl;
}

int main(int argc, char* argv[]) {
    Mat mat = (Mat_<float>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);

    cout << "mat=" << mat << endl << endl;

    add1mat(mat);

    add1array(mat);

    return 0;
}

// p36
// コード分析
// ・InputArrayは引数として受け取った場合は演算できないため、変換は必要（Matを引数として受け取る場合使うメリットない）
// ・InputArrayは「&」付いてないが、参照渡し