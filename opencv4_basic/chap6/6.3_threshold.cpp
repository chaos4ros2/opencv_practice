# include "common.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) 
{
  try
  {
      UMat src, dst;
      double thresh = 60, maxval = 180.0;
      int type = THRESH_BINARY;
  
      if (argc < 2)
          throw "no paramter.";
     
      imread(argv[1], IMREAD_GRAYSCALE).copyTo(src);
  
      equalizeHist(src, dst);
  
      if (argc >= 3)
          thresh = stof(argv[2]);
  
      if (argc >= 4)
          maxval = stof(argv[3]);
  
      if (argc >= 5)
      {
          switch (stoi(argv[4]))
          {
          case 0: type = THRESH_BINARY; break;
          case 1: type = THRESH_BINARY_INV; break;
          case 2: type = THRESH_TRUNC; break;
          case 3: type = THRESH_TOZERO; break;
          case 4: type = THRESH_TOZERO_INV; break;
          }
      }
  
      threshold(src, dst, thresh, maxval, type);
  
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