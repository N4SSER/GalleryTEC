#include <opencv2/opencv.hpp>
#include "hencoder.h"
#include "converter.h"
#include "RAID5.h"

using namespace std;
using namespace cv;
int main()
{
    vector<hencoder> hvec;
    RAID5 r;
    string sr;
    r.save("101010101010101010101010101010","im1");
    r.load("im1",2);
    while(true){
        Size size(200,150);
        Mat m;
        cin>>sr;
        if(sr =="0")
        {
            break;
        }
        Mat src=imread(sr);
        resize(src,m,size);
        converter c;
        vector<int> vc=c.vec_dec(m);
        hencoder h(vc);
        hvec.push_back(h);
        Mat dc = c.mat_rgb(h.decoded,m.rows,m.cols);
        imshow("decoded",dc);
        waitKey(0);
    }
    return 0;
}