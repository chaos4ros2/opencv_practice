# include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    try {
        // Mat src, dst;
        // Umatバージョン
        UMat src, dst;

        if (argc < 3)
            throw "few parameter, e.g. <file name> <scale W> [<scale H>].";

        float scaleW = stof(argv[2]);
        float scaleH = scaleW;
        if (argc == 4)
            scaleW = stof(argv[3]);

        // src = imread(argv[1]);
        // Umatバージョン
        imread(argv[1]).copyTo(src);
        
        if (src.empty()) 
            throw "faild open file.";

        // 縦横のピクセル数を計算する、intにキャストされるため、丸めはせず、小数点以下は切り捨てられる。
        int width = static_cast<int>(src.cols*scaleW);
        int height = static_cast<int>(src.rows*scaleH);
        resize(src, dst, Size(width, height));

        imshow("src", src);
        imshow("dst", dst);

        waitKey(0);
    } catch (const char* str) {
        cerr << str << endl;
    }
    return 0;
}
