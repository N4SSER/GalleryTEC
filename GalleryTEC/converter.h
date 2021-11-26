//
// Created by nasser on 20/11/21.
//

#ifndef GALLERYTEC_CONVERTER_H
#define GALLERYTEC_CONVERTER_H
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <math.h>
using namespace std;
using namespace cv;
class converter {
public:
    vector<int> vec_dec(Mat m);
    Mat mat_rgb(vector<int>,int r, int c);
};


#endif //GALLERYTEC_CONVERTER_H
