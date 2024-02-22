#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isso(long long int a) {
  if (a == 1 || a == 0)
    return false;
  for (long long int i = 2; i * i <= a; i++) {
    if (a % i == 0)
      return false;
  }
  return true;
}

long long int powint(long long int a, long long int b) {
  assert(b >= 0);
  if (b == 0)
    return 1;
  if (b == 1)
    return a;
  long long int ans = 1;
  long long int aa = powint(a, b / 2);
  ans *= aa * aa;
  if (b % 2)
    ans *= a;
  return ans;
}

vector<vector<int>> involve;

vector<int> dfs2(const int now, vector<bool> &used) {
  vector<int> ans;
  stack<int> s;
  s.push(now);
  while (!s.empty()) {
    int n = s.top();
    s.pop();
    if (used[n])
      continue;
    used[n] = true;
    ans.push_back(n);
    for (auto i : involve[n]) {
      if (!used[i])
        s.push(i);
    }
  }
  return ans;
}

int main() {
  while (1) {
    int num = 0;
    unordered_map<string, int> mp;
    set<int> ed;
    int N;
    cin >> N;
    if (!N)
      break;
    involve.clear();
    involve.resize(100000);
    for (int i = 0; i < N; ++i) {
      // ... (rest of the code is the same) ...
    }
  }
  return 0;
}