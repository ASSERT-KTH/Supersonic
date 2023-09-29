#include <iostream>
using namespace std;
int main() {
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      cout << i << "x" << j << "=" << i * j << endl;
    }
  }
  return 0;
}
