#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;

void linearFilter(cv::Mat input, cv::Mat kernel, cv::Mat &output) {
  const int dx = kernel.cols / 2;
  const int dy = kernel.rows / 2;

  for (int i = 0; i < input.rows; i++) {
    for (int j = 0; j < input.cols; j++) {
      float temp = 0.0f;
      for (int k = 0; k < kernel.rows; k++) {
        for (int l = 0; l < kernel.rows; l++) {
          int x = j - dx + l;
          int y = i - dy + k;
          if (x >= 0 && x < input.cols && y >= 0 && y < input.rows)
            temp += input.at<uchar>(y, x) * kernel.at<float>(k, l);
        }
      }
      output.at<uchar>(i, j) = temp;
    }
  }
}

int main(int argc, char* argv[]) {

  string filename = "D:/machine-vision/sunflower.jpg";
  cv::Mat src = cv::imread(filename, cv::IMREAD_GRAYSCALE);
  cv::namedWindow("src");
  cv::imshow("src", src);
  cv::waitKey(0);
  CV_Assert(src.type() == CV_8UC1); 

  // Create uniform 3x3 kernel
  cv::Mat kernel(3, 3, CV_32FC1, cv::Scalar(1.0/9.0));
  CV_Assert(kernel.type() == CV_32FC1);

  cv::Mat output;
  linearFilter(src, kernel, output);
  cv::namedWindow("Linear filter output");
  cv::imshow("Linear filter output", output);
  cv::waitKey(0);
  
  //Test with custom kernel on impulse image
  cv::Mat impulse = cv::Mat::zeros(5, 5, CV_8UC1);
  impulse.at<uchar>(2, 2) = 1;
  
  cv::Mat customKernel = (cv::Mat_<float>(3, 3) << 1,2,3,4,5,6,7,8,9);
  linearFilter(impulse, customKernel, output);
   
  for (int i = 0; i < output.rows; i++) {
    for (int j = 0; j < output.cols; j++) {
      cout << (int) output.at<uchar>(i, j) << " ";
    }
    cout << endl;
  }
  return 0;
}
