#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv) {
    Mat img;
    img = imread("D:/machine-vision/sunflower.jpg");
    if (!img.data) {
        printf("No image \n");
        return -1;
    }
    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", img);
    waitKey(0);
    return 0;
}