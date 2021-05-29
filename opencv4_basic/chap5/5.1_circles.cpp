# include "common.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    try {
        UMat img0(400, 400, CV_8UC3, Scalar(150, 150, 150));
        // (対象画像配列、円の中心座標、円の半径、円の色、線の太さ「マイナスの場合塗りつぶす」、枠線の種類、小数点以下桁数)
        circle(img0, Point(200, 200), 50, Scalar(25, 0, 0));
        imwrite("img0.jpg", img0);

        UMat img1(400, 400, CV_8UC3, Scalar(150, 150, 150));
        circle(img1, Point(200, 200), 100, Scalar(0, 255, 3), 3);
        imwrite("img1.jpg", img1);

        UMat img2(400, 400, CV_8UC3, Scalar(150, 150, 150));
        circle(img2, Point(200, 200), 150, Scalar(0, 0, 255), -1);
        imwrite("img2.jpg", img2);

        waitKey(0);

    } catch (const char* str) {
        cerr << str << endl;
    }
    return 0;
}