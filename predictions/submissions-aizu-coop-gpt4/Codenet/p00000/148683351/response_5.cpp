#include <iostream>
#include <sstream>
using namespace std;
int main() {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      ostringstream s;
      s << i << "x" << j << "=" << i * j;
      cout << s.str() << endl;
    }
  }
  return 0;
}