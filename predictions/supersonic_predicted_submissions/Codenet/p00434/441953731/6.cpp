#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  set<int> data;
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data.insert(n);
  }
  for (int i = 1; i <= 30; i++) {
    if (!data.count(i))
      cout << i << endl;
  }
}
