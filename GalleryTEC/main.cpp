#include <opencv2/opencv.hpp>
#include "hencoder.h"
using namespace std;
using namespace cv;

int main()
{
    vector<int> vr;
    vector<int> vg;
    vector<int> vb;
    Mat m = imread("ie.jpg");
    for(int i =0; i< m.rows;i++){
        for(int j =0; j<m.cols;j++){
            vr.push_back(m.at<Vec3b>(i,j)[2]);
            vg.push_back(m.at<Vec3b>(i,j)[1]);
            vb.push_back(m.at<Vec3b>(i,j)[0]);
        }
    }
    Mat nm(m.rows,m.cols,CV_8UC3);
    hencoder hr(vr);
    hencoder hg(vg);
    hencoder hb(vb);
    //DECODE
    int i=0;
    for(int x =0; x< m.rows;x++){
        for(int k =0; k<m.cols;k++){
            nm.at<Vec3b>(x,k)[2]=hr.decoded[i];
            nm.at<Vec3b>(x,k)[1]=hg.decoded[i];
            nm.at<Vec3b>(x,k)[0]=hb.decoded[i];
            i+=1;
        }

    }
    imshow("decode",nm);
    waitKey(0);
    return 0;
}