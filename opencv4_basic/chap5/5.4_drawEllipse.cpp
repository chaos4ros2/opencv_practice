# include "common.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    try {
        Mat mat = imread(argv[1]);
        if (mat.empty())
            throw "faild open file";

        Point center = Point(mat.cols / 2, mat.rows / 2);
        Size sz = Point(mat.cols / 2, mat.rows / 2);

        // (対象画像配列、中心座標、長径と短径、回転角度、円弧の開始角度、円弧の終了角度、楕円の色、枠線の太さ（マイナスの場合は塗りつぶす）、小数点以下桁数)
        ellipse(mat, center, sz, 0, 0, 360, Scalar(0, 255, 0), 3, 4);

        sz.width -= 20;
        sz.height -= 50;
        ellipse(mat, center, sz, 15, 10, 360, Scalar(0, 255, 255), 2, 4);

        imshow("mat", mat);
        imwrite("mat.jpg", mat);

        waitKey(0);

    } catch (const char* str) {
        cerr << str << endl;
    }
    return 0;
}