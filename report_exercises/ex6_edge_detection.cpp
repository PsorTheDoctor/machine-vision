#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace std;

void nonMaximaSuppression(int mat[5][5], int gradient[5][5]) {
  for (int x = 0; x < sizeof(mat); x+) {
    for (int y = 0; y < sizeof(mat[0]); y++) {
      // TODO!
    }
  }
}

int main(int argc, char* argv[]) {

  int mat[5][5] = {
    {66, 182, 69, 128, 77},
    {97, 162, 145, 53, 88},
    {93, 149, 103, 49, 34},
    {92, 161, 110, 106, 87},
    {89, 123, 105, 163, 138}
  }
  int gradient[5][5] = {
    {0, 1, 1, 0, 3},
    {1, 1, 1, 3, 1},
    {1, 0, 0, 1, 2},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 0}
  }
  nonMaximaSuppression(mat, gradient);
}