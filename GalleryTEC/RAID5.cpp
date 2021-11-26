//
// Created by nasser on 25/11/21.
//

#include <fstream>
#include <sstream>
#include <vector>
#include "RAID5.h"

void RAID5::save(string s,string img) {
    int i =0;
    int r =0;
    int par=3;
    auto* o = new string[4];
    while(r<s.length())
    {
        if(i==par){
            string ss;
            for(int k =0;k<4;k++)
            {
                if(k!=i)
                {
                    ss+= string (1,o[k][r]);
                }
            }
            string(1,o[i][i])+= parity(ss);
            par--;
        }
        else
        {
            o[i] += s[r];
            r++;
        }
        if(par<0)
            par =3;
        i++;
        if(i>3)
            i=0;
    }
    for(int x =0;x<4;x++)
    {
        string path = "Disk"+to_string(x)+"/"+img+".txt";
        ofstream(path)<<o[x];
    }
}

string RAID5::parity(string s) {
    string p ="1";
    int tp=0;
    for(int i =0; i<3;i++)
    {
        char ss = s[i];
        if(ss == '1')
        {
            tp++;
        }
    }
    if(tp%2==0)
        p="0";
    return p;
}

string RAID5::load(string img,int disk) {
    string temp;
    string out;
    vector<string> v;
    for(int x =0; x<4;x++)
    {
        if(x!=disk)
        {
            ifstream t("Disk"+ to_string(x)+"/"+img+".txt");
            stringstream buffer;
            buffer << t.rdbuf();
            v.push_back(buffer.rdbuf()->str());
        }
    }

    for(int k =0;k<v[0].length();k++)
    {
        string s(1, v[0][k]);
        string s1(1, v[1][k]);
        string s2(1, v[2][k]);
        string tm =  s+s1+s2;
        out += parity(tm);

    }
    cout<<out;
    return out;
}
