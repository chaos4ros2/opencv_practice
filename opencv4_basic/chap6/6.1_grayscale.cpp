# include "common.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    try {
        UMat src, dst;

        if (argc < 2)
           throw "no parameter";

        imread(argv[1]).copyTo(src);

        cvtColor(src, dst, COLOR_RGB2GRAY);

        imshow("src", src);
        imshow("dst", dst);
        imwrite("dst.jpg", dst);

        waitKey(0);

    } catch (const char* str) {
        cerr << str << endl;
    }
    return 0;
}