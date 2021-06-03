# include "common.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    try {
        Mat mat = imread(argv[1]);
        if (mat.empty())
            throw "faild open file";

        Point p = Point(50, mat.rows / 2 - 50);

        // (対象画像配列、描く文字列、文字列の左下隅の画像中の座標、フォントの種類、フォントのスケールファクタ、文字列の色、
        // フォントの描画に利用される線の太さ、線の種類、trueの場合は画像の原点は左下,そうでない場合は左上)
        putText(mat, "Hello OpenCV", p, FONT_HERSHEY_TRIPLEX, 0.8, Scalar(250, 200, 200), 2, LINE_AA);

        imshow("mat", mat);
        imwrite("mat.jpg", mat);

        waitKey(0);

    } catch (const char* str) {
        cerr << str << endl;
    }
    return 0;
}