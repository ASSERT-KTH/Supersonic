#include <cstdio>
#include <iostream>
using namespace std;

inline void repeat(int n) {
    for (int i = 0; i < n; i++) {}
}

int main() {
  int n;
  scanf("%d", &n);
  int min = 2000000, t, A[10001]{};
  repeat(n) {
    scanf("%d", &t);
    if (t < min)
      min = t;
    A[t]++;
  }
  A[min]--;
  cout << min;
  for (int i = min; i < 10001; i++) {
    repeat(A[i]) { cout << ' ' << i; }
  }
  cout << endl;
  return 0;
}