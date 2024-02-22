#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 1112;

int cubeNums[MAX_N];

int binarySearch(int a) {
  int low = 1, high = MAX_N - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (cubeNums[mid] <= a) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return cubeNums[high];
}

int calc(int z) {
  int z3 = z * z * z;
  int prevJ3 = binarySearch(z3);
  int ret = z3;
  for (int i = 1; i < z; i++) {
    int i3 = i * i * i;
    if (i3 + prevJ3 >= z3)
      break;
    ret = min(ret, z3 - i3 - prevJ3);
    prevJ3 = binarySearch(z3 - i3);
  }
  return ret;
}

int main() {
  for (int i = 1; i < MAX_N; i++)
    cubeNums[i] = i * i * i;
  int ans[MAX_N];
  for (int i = 1; i < MAX_N; i++)
    ans[i] = calc(i);
  int N;
  while (cin >> N, N)
    cout << ans[N] << endl;
  return 0;
}