﻿#include <stdio.h>
//#include "bmp.h"
#include "jpg.h"
#include "sift.h"
int main()
{
    Mat* color_image = read_jpg("2.JPG");    //read rgb image
    Mat* gray_image = RGB2Gray(color_image); //convert color image to gray image
    Mat* float_image = uchar2float(gray_image); //convert U8 to float
    List* key_points = Dog(float_image); // find the key point
    plot_points(color_image, key_points); // plot the key point
    write_bmp(color_image,"point2.bmp");

    free_mat(color_image);
    free_mat(gray_image);

    color_image = read_jpg("1.JPG");    //read rgb image
    gray_image = RGB2Gray(color_image); //convert color image to gray image
    float_image = uchar2float(gray_image); //convert U8 to float
    List* key_points2 = Dog(float_image); // find the key point
    plot_points(color_image, key_points2); // plot the key point
    write_bmp(color_image,"point1.bmp");

    return 0;
}
