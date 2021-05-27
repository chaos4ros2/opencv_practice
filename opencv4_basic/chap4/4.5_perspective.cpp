# include "common.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    try {
        Mat src, dst;
        Point2f dstPoint[4];
        int xMergin, yMergin;

        if (argc < 3) 
            throw "few parameter, e.g. <file name> <pattern>.";
        
        int pattern = stoi(argv[2]);
        imread(argv[1]).copyTo(src);

        int x0 = src.cols / 4;
        int x1 = (src.cols / 4) * 3;
        int y0 = src.rows / 4;
        int y1 = (src.rows / 4) * 3;
        Point2f srcPoint[] = {
            Point(x0, y0),
            Point(x0, y1),
            Point(x1, y1),
            Point(x1, y0)
        };

        switch (pattern)
        {
        case 0:
            xMergin = src.cols / 10;
            yMergin = src.rows / 10;
            dstPoint[0] = Point(x0 + xMergin, y0 + yMergin);
            dstPoint[1] = srcPoint[1];
            dstPoint[2] = srcPoint[2];
            dstPoint[3] = Point(x1 - xMergin, y0 + yMergin);
            break;

        case 1:
            xMergin = src.cols / 8;
            yMergin = src.rows / 8;
            dstPoint[0] = srcPoint[0];
            dstPoint[1] = srcPoint[1];
            dstPoint[2] = Point(x1 - xMergin, y1 - yMergin);
            dstPoint[3] = Point(x1 - xMergin, y0 + yMergin);
            break;

        case 2:
            xMergin = src.cols / 6;
            yMergin = src.rows / 6;
            dstPoint[0] = Point(x0 + xMergin, y0 + yMergin);
            dstPoint[1] = srcPoint[1];
            dstPoint[2] = Point(x1 - xMergin, y1 - yMergin);
            dstPoint[3] = srcPoint[3];
            break;
        }

        // 透視変換を求める(変換前と変換後の座標から透視変換を表す行列を返す)
        Mat perspectiveMmat = getPerspectiveTransform(srcPoint, dstPoint);
        warpPerspective(src, dst, perspectiveMmat, src.size(), INTER_CUBIC);

        imshow("src", src); // show images
        imshow("dst", dst);
        imshow("dst.jpg", dst);

        waitKey(0);

    } catch (const char* str) {
        cerr << str << endl;
    }
    return 0;
}