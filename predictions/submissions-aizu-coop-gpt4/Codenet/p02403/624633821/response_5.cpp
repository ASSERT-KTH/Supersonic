#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  vector<int> H, W;
  int h, w;
  while (1) {
    cin >> h >> w;
    if (h == 0 && w == 0)
      break;
    H.push_back(h);
    W.push_back(w);
  }
  for (size_t i = 0; i < H.size(); i++) {
    for (int j = 0; j < H[i]; j++) {
      cout << string(W[i], '#') << "\n";
    }
    cout << "\n";
  }
  return 0;
}