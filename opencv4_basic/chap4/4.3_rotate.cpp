# include "common.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    try {
        Mat src, dst;

        if (argc < 3) 
            throw "few parameter, e.g. <file name> <angle>.";
        
        float angle = stof(argv[2]);

        src = imread(argv[1]);
        if (src.empty()) // Matオブジェクトのemptyメソッドで画像が正常に読み込まれたかのチェック
            throw "faildopen file.";

        // 回転中心の指定
        Point2f center = Point2f(static_cast<float>(src.cols / 2),
            static_cast<float>(src.rows / 2));
    
        // ２次元回転のアフィン変換行列の計算
        Mat affineTrans= getRotationMatrix2D(center, angle, 2.0);

        // debug affineTransの値の理由は不明
        cout << center << endl;
        cout << affineTrans << endl;
        // 引数に2 * 3のMat行列を渡すことで回転処理を行う
        warpAffine(src, dst, affineTrans, src.size(), INTER_CUBIC, BORDER_REPLICATE);

        imshow("src", src); // show images
        imshow("dst", dst);

        imwrite("dst.jpg", dst); // write images

        waitKey(0);

            } catch (const char* str) {
        cerr << str << endl;
    }
    return 0;
}