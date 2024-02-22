#include <iostream>
#include <algorithm>
#include <cstring>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;

const int MAX_PERMUTATIONS = 10000000; // Maximum number of permutations

string s;
string vs[MAX_PERMUTATIONS]; // Array to store permutations

void dfs(string t, int now, bool used[]) {
  if (now == s.size()) {
    vs[0] = t;
    return;
  }
  if (t[now] != 'z' && !used[t[now] + 1 - 'a']) {
    string tmp = t;
    tmp[now] = tmp[now] + 1;
    used[tmp[now] - 'a'] = true;
    dfs(tmp, now + 1, used);
    used[tmp[now] - 'a'] = false; // Reset the used flag after backtracking
  }
  if (t[now] == 'a' || used[t[now] - 'a']) {
    dfs(t, now + 1, used);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  while (1) {
    cin >> s;
    if (s == "#")
      break;
    memset(vs, 0, sizeof(vs)); // Reset the permutation array
    bool used[26] = {false}; // Array to keep track of character occurrences
    dfs(s, 0, used);
    int ans = 1; // Store the size directly while generating permutations
    sort(vs, vs + ans);
    cout << ans << endl;
    if (ans <= 10) {
      rep(i, 0, ans) { cout << vs[i] << endl; }
    } else {
      rep(i, 0, 5) { cout << vs[i] << endl; }
      rep(i, ans - 5, ans) { cout << vs[i] << endl; }
    }
  }
}