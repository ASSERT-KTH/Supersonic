#include <iostream>
using namespace std;

const int MAX_N = 1112;
int tb[MAX_N], ans[MAX_N];

int nr(int a) {
  int low = 1, high = MAX_N - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (tb[mid] > a) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return tb[high];
}

int calc(int z) {
  int z3 = z * z * z;
  int ret = z3;
  for (int i = 1; i < z; i++) {
    int i3 = i * i * i;
    int j3 = nr(z3 - i3);
    if (i3 + j3 >= z3) {
      break;
    }
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}

int main() {
  for (int i = 1; i < MAX_N; i++) {
    tb[i] = i * i * i;
    ans[i] = calc(i);
  }
  
  int N;
  while (cin >> N, N) {
    cout << ans[N] << endl;
  }
  
  return 0;
}