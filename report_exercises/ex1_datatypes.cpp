#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char** argv) {
  cv::Mat mat;
  size_t size;

  // A single channel 8-bit unsigned integer image with dimensions 1024x768
  mat = cv::Mat::zeros(768, 1024, CV_8UC1);
  size = mat.total() * mat.elemSize();
  cout << size << endl;

  // A 3-channel 32-bit floating point image with dimensions 640x480
  mat = cv::Mat::zeros(480, 640, CV_32FC3);
  size = mat.total() * mat.elemSize();
  cout << size << endl;

  // A 2-channel 16-bit signed integer image with dimensions 1280x720
  mat = cv::Mat::zeros(720, 1280, CV_16SC2);
  size = mat.total() * mat.elemSize();
  cout << size << endl;

  return 0;
}