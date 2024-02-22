#include <iostream>
using namespace std;

const int START = 1;
const int END = 9;

int main() {
  for (int i = START; i <= END; i++) {
    for (int j = START; j <= END; j++) {
      cout << i << "x" << j << "=" << i * j << '\n';
    }
  }
  return 0;
}