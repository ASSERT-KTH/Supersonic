#include <iostream>
using namespace std;
int main() {
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cout << i << "x" << j << "=" << i * j << endl;
    }
  }
  return 0;
}
