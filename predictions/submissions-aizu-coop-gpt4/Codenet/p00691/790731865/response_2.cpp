#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int calc(const vector<int>& tb, int z) {
  int z3 = z * z * z, ret = z3;
  
  vector<int> nr(z3 + 1);
  int j = 1;
  for (int i = 0; i <= z3; i++) {
    if (j < tb.size() && tb[j] <= i) {
      j++;
    }
    nr[i] = tb[j - 1];
  }

  for (int i = z - 1; i >= 1; i--) {
    int i3 = i * i * i, j3 = nr[z3 - i3];
    if (i3 + j3 >= z3) {
      break;
    }
    ret = min(ret, z3 - i3 - j3);
  }

  return ret;
}

int main() {
  vector<int> tb(1112), ans(1112);
  for (int i = 1; i < 1112; i++) {
    tb[i] = i * i * i;
  }
  for (int i = 1; i < 1112; i++) {
    ans[i] = calc(tb, i);
  }
  int N;
  while (cin >> N, N) {
    cout << ans[N] << endl;
  }
}