#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int inputRows = 10;
const int inputCols = 10;

double L2norm(int px, int py, int qx, int qy) {
  // Euclidean distance
  return sqrt(pow(qx - px, 2) + pow(qy - py, 2));
}

void chamferTransform(double input[10][10], double output[10][10]) {
  for (int x = 1; x < inputRows - 1; x++) {
    for (int y = 1; y < inputCols - 1; y++) {

      double dist1 = L2norm(x, y, x-1, y-1) + input[x-1][y-1];
      double dist2 = L2norm(x, y, x, y-1) + input[x][y-1];
      double dist3 = L2norm(x, y, x+1, y-1) + input[x+1][y-1];
      double dist4 = L2norm(x, y, x-1, y) + input[x-1][y];

      output[x][y] = max(max(dist1, dist2), max(dist3, dist4));
    }
  }
}

void print(double mat[10][10]) {
  for (int x = 0; x < inputRows; x++) {
    for (int y = 0; y < inputCols; y++) {
      cout << round(mat[x][y] * 100) / 100 << " ";
    } cout << endl;
  } cout << endl;
}

int main(int argc, char** argv) {
    
  double mat[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };
  double firstPass[10][10];
  double secondPass[10][10];

  chamferTransform(mat, firstPass);
  print(firstPass);
  chamferTransform(firstPass, secondPass);
  print(secondPass);
  return 0;
}