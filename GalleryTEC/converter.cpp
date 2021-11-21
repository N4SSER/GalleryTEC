//
// Created by nasser on 20/11/21.
//

#include "converter.h"

vector<int> converter::vec_dec(Mat m) {
    vector<int> v;
    for(int i=0;i<m.rows;i++)
    {
        for(int j =0; j<m.cols;j++)
        {
            int c = m.at<Vec3b>(i,j)[2]*pow(16,4)+ m.at<Vec3b>(i,j)[1]*pow(16,2) +m.at<Vec3b>(i,j)[0]*pow(16,0);
            v.push_back(c);
        }
    }
    return v;
}

Mat converter::mat_rgb(vector<int> v ,int rw, int c) {
    int x =0;
    Mat m(rw,c,CV_8UC3);
    for(int i=0;i<rw;i++)
    {
        for(int j =0; j<c;j++)
        {
            int b = v[x]%256;
            int g_0 = v[x]%65536-b;
            int r_0 = v[x] -g_0-b;
            int g = g_0/256;
            int r = r_0/65536;
            m.at<Vec3b>(i,j)[0] = b;
            m.at<Vec3b>(i,j)[1] = g;
            m.at<Vec3b>(i,j)[2] = r;
            x++;
        }
    }
    return m;

}
