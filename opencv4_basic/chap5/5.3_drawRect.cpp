# include "common.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    try {
        Mat mat = imread(argv[1]);
        if (mat.empty())
            throw "faild open file";

        Point p0 = Point(mat.cols / 8, mat.rows / 8);
        Point p1 = Point(mat.cols * 7 / 8, mat.rows * 7 / 8);
        // (対象画像配列、1番目端点、2番目端点、矩形の色、矩形の枠線の太さ、枠線の種類、小数点以下桁数)
        rectangle(mat, p0, p1, Scalar(0, 255, 0), 5, 8);

        Point p2 = Point(mat.cols*2 / 8, mat.rows*2 / 8);
        Point p3 = Point(mat.cols*6 / 8, mat.rows*6 / 8);
        rectangle(mat, p2, p3, Scalar(0, 255, 255), 2, 4);

        imshow("mat", mat);
        imwrite("mat.jpg", mat);

        waitKey(0);

    } catch (const char* str) {
        cerr << str << endl;
    }
    return 0;
}