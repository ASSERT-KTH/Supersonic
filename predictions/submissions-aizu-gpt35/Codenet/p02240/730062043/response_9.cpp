#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& join, int x) {
  if (x == join[x])
    return x;
  return join[x] = find(join, join[x]);
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, s, t;
  cin >> n >> m;

  vector<int> join(n), num(n);
  for (int i = 0; i < n; ++i) {
    join[i] = i;
    num[i] = 0;
  }

  for (int i = 0; i < m; ++i) {
    cin >> s >> t;
    s = find(join, --s);
    t = find(join, --t);
    if (s != t) {
      if (num[s] < num[t])
        join[s] = t;
      else {
        join[t] = s;
        if (num[s] == num[t])
          ++num[s];
      }
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> s >> t;
    s = find(join, --s);
    t = find(join, --t);
    cout << (s == t ? "yes\n" : "no\n");
  }
  return 0;
}