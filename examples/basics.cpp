// Credits: Thorbjoern Mosekjaer Iversen

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    std::string filename = "D:/machine-vision/sunflower.jpg";
    cv::Mat src = cv::imread(filename, cv::IMREAD_COLOR);
    if (!src.data) {
        printf("No image \n");
        return -1;
    }
    cv::namedWindow("src");
    cv::imshow("src", src);
    cv::waitKey(0);

    CV_Assert(src.type() == CV_8UC3);

    // Rotate image
    cv::Mat src_rotated(src.cols, src.rows, src.type());
    for(int i=0; i<src_rotated.rows; i++){
        for(int j=0; j<src_rotated.cols; j++){
            src_rotated.at<cv::Vec3b>(i, j) = src.at<cv::Vec3b>(src_rotated.cols-j-1, i);
        }
    }
    cv::namedWindow("src_rotated");
    cv::imshow("src_rotated", src_rotated);
    cv::waitKey(0);

    // Show BGR and HLS channels
    cv::Mat src_hls;
    cv::cvtColor(src, src_hls, cv::COLOR_BGR2HLS);

    std::vector<cv::Mat> bgrChannels, hlsChannels;
    cv::split(src, bgrChannels);
    cv::split(src_hls, hlsChannels);

    int flags = cv::WINDOW_AUTOSIZE;
    // cv::namedWindow("src", flags);
    // cv::namedWindow("b", flags);
    // cv::namedWindow("g", flags);
    // cv::namedWindow("r", flags);
    // cv::namedWindow("h", flags);
    // cv::namedWindow("l", flags);
    // cv::namedWindow("s", flags);

    // cv::imshow("b", bgrChannels[0]);
    // cv::imshow("g", bgrChannels[1]);
    // cv::imshow("r", bgrChannels[2]);
    // cv::imshow("h", hlsChannels[0]);
    // cv::imshow("l", hlsChannels[1]);
    // cv::imshow("s", hlsChannels[2]);
    cv::waitKey(0);

    cv::Mat spoon_hls = cv::Mat::zeros(src_hls.rows, src_hls.cols, src_hls.type());
    for(int i = 0; i < src_hls.rows; i++) {
        for(int j = 0; j < src_hls.cols; j++) {
            cv::Vec3b pixel = src_hls.at<cv::Vec3b>(i, j);
            if(pixel[0] > 150 && pixel[1] < 150 && pixel[2] > 150) {
                spoon_hls.at<cv::Vec3b>(i, j) = pixel;
            }
        }
    }
    cv::Mat spoon;
    cv::cvtColor(spoon_hls, spoon, cv::COLOR_HLS2BGR);
    cv::namedWindow("spoon");
    cv::imshow("spoon", spoon);
    cv::waitKey(0);
    return 0;
}
