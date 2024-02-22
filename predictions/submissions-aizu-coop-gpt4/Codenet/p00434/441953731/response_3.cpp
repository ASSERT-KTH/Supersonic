#include <iostream>
using namespace std;

int main() {
  bool data[31] = {false}; // boolean array to store presence of numbers
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data[n] = true; // mark the number as present
  }
  for (int i = 1; i <= 30; i++) {
    if (!data[i]) // check if number is not present
      cout << i << endl;
  }
}