#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  double real1, imag1, real2, imag2;
  cin >> real1 >> imag1 >> real2 >> imag2;
  
  double diffReal = real1 - real2;
  double diffImag = imag1 - imag2;
  
  double absoluteDiff = sqrt(diffReal * diffReal + diffImag * diffImag);
  
  printf("%.5f\n", absoluteDiff);
  
  return 0;
}