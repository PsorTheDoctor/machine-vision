#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace std;

int countNumberOfRice(cv::Mat input) {
  cv::Mat binary, eroded, labels, stats;
  cv::threshold(input, binary, 150, 255, 0);
  cv::erode(binary, eroded, 2);
  // connectedComponents don't work!!
  // int i, nComps = cv::connectedComponentsWithStats(eroded, labels, stats, cv::noArray());

  cv::namedWindow("Image");
  cv::imshow("Image", eroded);
  cv::waitKey(0);
  return 0;
}

int main(int argc, char* argv[]) {
  cv::Mat img = cv::imread("D:/machine-vision/rice.png", cv::IMREAD_GRAYSCALE);
  if (!img.data) {
    printf("No image \n");
    return -1;
  }
  int numOfRice = countNumberOfRice(img);
  cout << numOfRice << endl;
  return 0;
}
