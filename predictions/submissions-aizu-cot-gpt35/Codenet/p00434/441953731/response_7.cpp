#include <iostream>
using namespace std;

int main() {
  bool present[31] = {false};
  int n;
  
  for (int i = 0; i < 28; i++) {
    cin >> n;
    present[n] = true;
  }
  
  for (int i = 1; i <= 30; i++) {
    if (!present[i])
      cout << i << endl;
  }
}