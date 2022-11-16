#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

void medianSubtraction(int mat1[5][5], int mat2[5][5], int mat3[5][5], int output[5][5]) {
  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 5; y++) {
      int temp[3] = {mat1[x][y], mat2[x][y], mat3[x][y]};
      sort(temp, temp + 3);
      // Picking the middle value, so it's median
      output[x][y] = temp[1];
      cout << output[x][y] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void absDiff(int mat1[5][5], int mat2[5][5]) {
  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 5; y++) {
      cout << abs(mat1[x][y] - mat2[x][y]) << " ";
    }
    cout << endl;
  }
}

int main(int argc, char** argv) {

  int frame1[5][5] = {
    {1, 3, 10, 4, 0},
    {3, 9, 9, 10, 1},
    {4, 9, 10, 2, 3},
    {0, 11, 0, 3, 2},
    {2, 4, 2, 1, 4}
  };

  int frame2[5][5] = {
    {1, 10, 3, 3, 1},
    {9, 10, 10, 4, 2},
    {10, 11, 3, 3, 1},
    {9, 2, 0, 2, 1},
    {1, 3, 3, 2, 2}
  };

  int frame3[5][5] = {
    {2, 2, 3, 1, 1},
    {5, 4, 10, 4, 2},
    {2, 11, 10, 10, 1},
    {0, 9, 11, 4, 1},
    {2, 9, 2, 1, 2}
  };

  int median[5][5];
  medianSubtraction(frame1, frame2, frame3, median);

  int frame4[5][5] = {
    {2, 2, 2, 4, 0},
    {4, 1, 2, 3, 2},
    {3, 3, 3, 2, 2},
    {1, 3, 3, 4, 1},
    {3, 3, 2, 1, 4}
  };

  absDiff(frame4, median);
  return 0;
}