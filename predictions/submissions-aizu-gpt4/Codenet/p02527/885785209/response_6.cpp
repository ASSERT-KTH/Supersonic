#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  for(const auto &i : a) cout << i << ' ';
  cout << '\n';
  return 0;
}