#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace std;

void computeProjection(double input[3][1], double output[3][1]) {
  double fx = 1008.2;
  double fy = 1008.2;
  double cx = 705.9;
  double cy = 549.1;

  double K[3][3] = {
    {fx, 0, cx},
    {0, fy, cy},
    {0,  0,  1}
  };
  double T[3][4] = {
    {0.5,  0.866, 0, 0.1},
    {0.866, -0.5, 0, 0.1},
    {0,        0, 1, 1.2}
  };
  double KT[3][3];

  double X[3][1] = {
    {input[0][0]}, {input[1][0]}, {input[2][0]}
  };

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      KT[i][j] = 0;
      for (int k = 0; k < 3; k++) {
        KT[i][j] += K[i][k] * T[k][j];
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      output[i][j] = 0;
      for (int k = 0; k < 3; k++) {
        output[i][j] += KT[i][k] * X[k][j];
      }
    }
  }
}

int main(int argc, char* argv[]) {
  double X[3][1] = {{0.1}, {0.2}, {0.0}};
  double result[3][1];

  computeProjection(X, result);
  for (int i = 0; i < 3; i++) {
    cout << result[i][0] << endl;
  }
}
