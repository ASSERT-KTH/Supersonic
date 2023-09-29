#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int main() {
  bool data[N] = {};
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data[n-1] = true;
  }
  for (int i = 0; i < N; i++) {
    if (!data[i])
      cout << i+1 << endl;
  }
}