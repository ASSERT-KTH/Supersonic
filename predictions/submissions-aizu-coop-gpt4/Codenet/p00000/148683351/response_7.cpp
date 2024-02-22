#include <iostream>
using namespace std;

int main() {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      cout << to_string(i) + "x" + to_string(j) + "=" + to_string(i * j) + '\n';
    }
  }
  return 0;
}