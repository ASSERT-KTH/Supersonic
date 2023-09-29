#include <iostream>
#include <vector>
using namespace std;

vector<int> join, num;

int find(int x) {
  if (x == join[x]) return x;
  return join[x] = find(join[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, s, t;
  cin >> n >> m;
  join.resize(n);
  num.resize(n);
  for (int i = 0; i < n; i++) {
    join[i] = i;
    num[i] = 0;
  }
  while (m--) {
    cin >> s >> t;
    s = find(s);
    t = find(t);
    if (s != t) {
      if (num[s] < num[t])
        join[s] = t;
      else {
        join[t] = s;
        if (num[s] == num[t])
          num[s]++;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    cin >> s >> t;
    if (find(s) == find(t))
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}