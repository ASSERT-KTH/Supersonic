#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int square = n * n;  // store the square of n
  cout << square * n << endl;  // multiply the square by n to get the cube
  return 0;
}