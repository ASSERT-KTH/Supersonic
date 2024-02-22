#include <cstdio>
#include <string>
#include <sstream>
using namespace std;
int main() {
  ostringstream os;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      int result = i * j;
      os << i << "x" << j << "=" << result << "\n";
    }
  }
  printf("%s", os.str().c_str());
  return 0;
}