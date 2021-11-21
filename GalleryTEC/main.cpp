#include <opencv2/opencv.hpp>
#include "hencoder.h"
#include "converter.h"
using namespace std;
using namespace cv;
int main()
{
    Size size(100,80);//the dst image size,e.g.100x100
    Mat m;//dst image
    Mat src=imread("ie.jpg");//src image
    resize(src,m,size);//resize image;
    converter c;
    vector<int> vc=c.vec_dec(m);
    hencoder h(vc);
    Mat dc = c.mat_rgb(h.decoded,m.rows,m.cols);
    imshow("decoded",dc);
    waitKey(0);

    return 0;
}