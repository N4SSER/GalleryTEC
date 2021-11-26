//
// Created by nasser on 25/11/21.
//

#ifndef GALLERYTEC_RAID5_H
#define GALLERYTEC_RAID5_H

#include <iostream>

using namespace std;
class RAID5 {
private:
    string parity(string s);

public:
    void save(string s,string img);
    string load(string img,int disk);
};


#endif //GALLERYTEC_RAID5_H
