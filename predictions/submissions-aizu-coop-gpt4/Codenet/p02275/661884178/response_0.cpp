#include <bits/stdc++.h>
using namespace std;
#define r(i, n) for (auto i = 0; i < n; i++)
#define s(c) static_cast<int>((c).size())
int main() {
  int n;
  scanf("%d", &n);
  int min = 2000000, t, A[10001]{};
  r(i, n) {
    scanf("%d", &t);
    if (t < min)
      min = t;
    A[t]++;
  }
  A[min]--;
  cout << min;
  // Start the loop from min+1 because we have already printed the min value
  for (int i = min+1; i < 10001; i++) {
    r(j, A[i]) { cout << ' ' << i; }
  }
  cout << endl;
  return 0;
}