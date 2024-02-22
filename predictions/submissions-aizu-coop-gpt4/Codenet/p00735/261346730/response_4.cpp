#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
bitset<300000 + 1> checked;
vector<int> lists;
vector<int> ans;
// Precomputed results of modulus operation for 7.
int mod7[7] = {0, 1, 2, 3, 4, 5, 6};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  rep2(i, 2, 300000 + 1) {
    if (checked[i])
      continue;
    // Use lookup table to replace modulus operation.
    if (mod7[i % 7] == 1 || mod7[i % 7] == 6) {
      lists.push_back(i);
      int k = 1;
      while (i * k <= 300000) {
        checked[i * k] = true;
        k++;
      }
    }
  }
  // Reserve space for "ans" vector in advance.
  ans.reserve(lists.size());
  while (true) {
    int n;
    cin >> n;
    if (n == 1)
      break;
    for (auto p : lists) {
      if (n % p == 0) {
        ans.push_back(p);
      }
    }
    cout << n << ':';
    for (auto num : ans) { cout << " " << num; }
    cout << endl;
    ans.clear();
  }
}