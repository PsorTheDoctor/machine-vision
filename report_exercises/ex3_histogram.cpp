#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <map>

using namespace std;

void computeHist(int mat[5][6]) {
  map<int, int> uniqueValues;

  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 6; y++) {
      int val = mat[x][y];

      if (uniqueValues.find(val) != uniqueValues.end()) {
        int quantity = ++uniqueValues.at(val);
        uniqueValues.erase(uniqueValues.find(val));
        uniqueValues.insert(pair<int, int>(val, quantity));
      } else {
        uniqueValues.insert(pair<int, int>(val, 1));
      }
    }
  }
  for (auto i = uniqueValues.begin(); i != uniqueValues.end(); ++i) {
    cout << i->first << '\t' << i->second << endl;
  }
}

int main(int argc, char* argv[]) {
  int mat[5][6] = {
    {5, 7, 3, 5, 4, 6},
    {2, 0, 5, 1, 2, 3},
    {6, 5, 4, 8, 3, 1},
    {5, 6, 4, 5, 0, 5},
    {8, 9, 3, 6, 7, 7}
  };
  computeHist(mat);

  return 0;
}
