#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      string output = to_string(i) + "x" + to_string(j) + "=" + to_string(i * j) + '\n';
      cout << output;
    }
  }
  return 0;
}