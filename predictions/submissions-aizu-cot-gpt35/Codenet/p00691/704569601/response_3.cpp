#include <iostream>
using namespace std;

int main() {
  int z;
  while (cin >> z && z) {
    int ans = 0;
    int zCube = z * z * z;
    for (int x = 1; x * x * x <= zCube; x++) {
      int maxyCube = zCube - x * x * x;
      int y = 1;
      while (y * y * y <= maxyCube) {
        ans = max(ans, x * x * x + y * y * y);
        y++;
      }
    }
    cout << zCube - ans << endl;
  }
}