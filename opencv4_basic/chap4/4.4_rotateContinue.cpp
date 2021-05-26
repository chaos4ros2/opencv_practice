# include "common.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    try {
        Mat src, dst;

        if (argc < 2) 
            throw "few parameter, e.g. <file name>.";
        
        imread(argv[1]).copyTo(src);

        if (src.empty()) // Matオブジェクトのemptyメソッドで画像が正常に読み込まれたかのチェック
            throw "faildopen file.";

        // 回転中心の指定
        Point2f center = Point2f(static_cast<float>(src.cols / 2),
            static_cast<float>(src.rows / 2));
    
        imshow("src", src); // show images
        // http://opencv.jp/opencv-2svn/cpp/user_interface.html#cv-namedwindow
        namedWindow("dst", WINDOW_AUTOSIZE);
        
        // 0.5℃刻みで連続的に増加させる
        for (float angle = 0.0; angle < 360.0; angle += .5)
        {
            // ２次元回転のアフィン変換行列の計算
            Mat affineTrans= getRotationMatrix2D(center, angle, 1.0);
            // 引数に2 * 3のMat行列を渡すことで回転処理を行う
            warpAffine(src, dst, affineTrans, src.size(), INTER_CUBIC, BORDER_REPLICATE);
            imshow("dst", dst); // show images
            if (waitKey(1) >= 0) break;
        }

    } catch (const char* str) {
        cerr << str << endl;
    }
    return 0;
}