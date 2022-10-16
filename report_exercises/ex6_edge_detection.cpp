#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <algorithm>

using namespace std;

const int inputRows = 5;
const int inputCols = 5;

void nonMaximaSuppression(int input[5][5], int gradient[5][5], int output[5][5]) {
  for (int x = 0; x < inputRows; x++) {
    for (int y = 0; y < inputCols; y++) {
      int maxVal = 0;
      switch (gradient[x][y]) {
        case 0:
        if (y > 0) {
          maxVal = max(input[x][y-1], input[x][y]);
        } else if (y < 4) {
          maxVal = max(maxVal, input[x][y+1]);
        } else {
          maxVal = input[x][y];
        } break;

        case 1:
        if (x > 0 && y < 4) {
          maxVal = max(input[x-1][y+1], input[x][y]);
        } else if (x < 4 && y > 0) {
          maxVal = max(maxVal, input[x+1][y-1]);
        } else {
          maxVal = input[x][y];
        } break;

        case 2:
        if (x > 0) {
          maxVal = max(input[x-1][y], input[x][y]);
        } else if (x < 4) {
          maxVal = max(maxVal, input[x+1][y]);
        } else {
          maxVal = input[x][y];
        } break;

        case 3:
        if (x > 0 && y > 0) {
          maxVal = max(input[x-1][y-1], input[x][y]);
        } else if (x < 4 && y < 4) {
          maxVal = max(maxVal, input[x+1][y+1]);
        } else {
          maxVal = input[x][y];
        } break;

        default:
        cout << "Invalid gradient value!" << endl;
        break;
      }
      if (input[x][y] == maxVal)
        output[x][y] = maxVal;
      else
        output[x][y] = 0;
    }
  }
}

void threshold(int input[5][5], int output[5][5], int low, int high) {
  for (int x = 0; x < inputRows; x++) {
    for (int y = 0; y < inputCols; y++) {
      if (input[x][y] < low || input[x][y] > high)        
        output[x][y] = 0;
    }
  }
}

void print(int mat[5][5]) {
  for (int x = 0; x < inputRows; x++) {
    for (int y = 0; y < inputCols; y++) {
      cout << mat[x][y] << " ";
    } cout << endl;
  } cout << endl;
}

int main(int argc, char* argv[]) {

  int input[5][5] = {
    {66, 182, 69, 128, 77},
    {97, 162, 145, 53, 88},
    {93, 149, 103, 49, 34},
    {92, 161, 110, 106, 87},
    {89, 123, 105, 163, 138}
  };
  int gradient[5][5] = {
    {0, 1, 1, 0, 3},
    {1, 1, 1, 3, 1},
    {1, 0, 0, 1, 2},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 0}
  };
  int output[5][5];

  nonMaximaSuppression(input, gradient, output);
  print(output);
  threshold(input, output, 125, 150);
  print(output);
}
