#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& join, int x) {
  if (x != join[x])
    join[x] = find(join, join[x]);
  return join[x];
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, s, t;
  cin >> n >> m;
  
  vector<int> join(n), num(n);
  join.reserve(n);
  num.reserve(n);

  for (int i = 0; i < n; i++) {
    join[i] = i;
    num[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    s = find(join, s);
    t = find(join, t);
    if (s != t) {
      if (num[s] < num[t])
        join[s] = join[t];
      else {
        join[t] = join[s];
        if (num[s] == num[t])
          num[s]++;
      }
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (find(join, s) == find(join, t))
      cout << "yes\n";
    else
      cout << "no\n";
  }
}