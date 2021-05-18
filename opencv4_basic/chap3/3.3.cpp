# include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>
# pragma comment(lib, "opencv_world400.lib")

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "no parameter." << endl;
        return -1;
    }

    // 疑問：{}の意味
    // Mat to UMat - 1
    {
        Mat mat = imread(argv[1]);
        // convert Mat to UMat
        UMat umat;
        mat.copyTo(umat);
    }

    // Mat to UMat - 2
    {
        UMat umat;
        // convert Mat to UMat
        imread(argv[1]).copyTo(umat);
    }
    // Mat to UMat - 3
    {
        Mat mat = imread(argv[1]);
        // convert Mat to UMat
        UMat umat = mat.getUMat(ACCESS_RW);
    }

    // UMat to Mat
    {
        UMat umat;
        imread(argv[1]).copyTo(umat);
        // convert Mat to UMat
        Mat mat = umat.getMat(ACCESS_RW);
    }
    return 0;
}

// p34
// UMat <=> Matの方法：
// ・MatオブジェクトのgetUMatメソッドでUMatへコピーする
// ・UMatオブジェクトのgetMatメソッドでMatへコピーする
// ・Mat/UMatのcopyToメソッドを使う