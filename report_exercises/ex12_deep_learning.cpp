#include <iostream>
#include <math.h>

using namespace std;

double sigmoid(double arg) {
  return 1 / (1 + exp(-arg));
}

int main(int argc, char** argv) {
  double x[4] = {1, -4, 3, 8};
  double w[4] = {3.9, 1.1, 2.5, -1.3};
  double b = 3;
  double sum = 0;

  for (int i = 0; i < 4; i++) {
    sum += w[i] * x[i] + b;
  }
  cout << sigmoid(sum) << endl;
  return 0;
}
