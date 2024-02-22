#include <vector>
#include <iostream>
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
  for (int i = 0; i < H.size(); i++) {
    string row(W[i], '#');
    for (int j = 0; j < H[i]; j++) {
      printf("%s\n", row.c_str());
    }
    printf("\n");
  }
  return 0;
}