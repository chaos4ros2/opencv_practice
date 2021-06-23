# include "common.h"

using namespace cv;
using namespace std;

// cv::bitwise_not
// 行列のすべてのビットを反転する

// void bitwise_not(InputArray src, 入力画像（行列）
//                  OutputArray dst, 出力画像（行列）
//                  InputArray mask=noArray()) オプション処理マスク、8ビットのシングルチャンネル画像
int main(int argc, char* argv[]) 
{
  try
  {
      UMat src, dst;

      if (argc < 2)
          throw "no paramter.";
     
      imread(argv[1]).copyTo(src);
  
      bitwise_not(src, dst);

      imshow("src", src);
      imshow("dst", dst);
      imwrite("dst.jpg", dst);
  
      waitKey(0);
  }
  catch (const char* str)
  {
      cerr << str << endl;
  }
  return 0;
}