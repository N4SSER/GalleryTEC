//
// Created by pablo on 21/11/21.
//

#include "Raid.h"

void Raid::cropimg() {
    Mat src=imread("ie.jpg");//src image
    string path1="/home/pablo/CLionProjects/GalleryTEC/GalleryTEC/Raids/Disco-1/Ie-1.jpg";
    string path2="/home/pablo/CLionProjects/GalleryTEC/GalleryTEC/Raids/Disco-2/Ie-2.jpg";
    string path3="/home/pablo/CLionProjects/GalleryTEC/GalleryTEC/Raids/Disco-3/Ie-3.jpg";
    string path4="/home/pablo/CLionProjects/GalleryTEC/GalleryTEC/Raids/Disco-4/Ie-4.jpg";
    Disco1= Rect(0,0,472,66.25);
    Disco2= Rect(0,66.25,472,66.25);
    Disco3= Rect(0,132.5,472,66.25);
    Disco4= Rect(0,198.75,472,66.25);
    Mat cropped_image1 = src(Disco1);
    Mat cropped_image2 = src(Disco2);
    Mat cropped_image3 = src(Disco3);
    Mat cropped_image4 = src(Disco4);
    imwrite(path1, cropped_image1);
    imwrite(path2, cropped_image2);
    imwrite(path3, cropped_image3);
    imwrite(path4, cropped_image4);
    cout << "Successfully saved the images" << endl;
}