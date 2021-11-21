//
// Created by pablo on 21/11/21.
//

#ifndef GALLERYTEC_RAID_H
#define GALLERYTEC_RAID_H
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <math.h>
using namespace cv;
using namespace std;
class Raid {
public:
    Rect Disco1;
    Rect Disco2;
    Rect Disco3;
    Rect Disco4;
    void cropimg();
};


#endif //GALLERYTEC_RAID_H
