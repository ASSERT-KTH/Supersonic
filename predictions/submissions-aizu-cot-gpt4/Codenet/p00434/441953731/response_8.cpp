#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bitset<30> data;
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data.set(n - 1); //subtracting 1 because bitset is 0-indexed
  }
  for (int i = 1; i <= 30; i++) {
    if (!data.test(i - 1))
      cout << i << '\n';
  }
}