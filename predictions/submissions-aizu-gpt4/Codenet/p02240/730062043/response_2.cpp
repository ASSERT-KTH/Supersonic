#include <iostream>
using namespace std;

constexpr int MAX = 100000;

int join[MAX], num[MAX];

int find(int x) {
  if (x != join[x])
    join[x] = find(join[x]);
  return join[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, s, t;
  cin >> n >> m;
  
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
      else if (num[s] > num[t])
        join[t] = s;
      else {
        join[t] = s;
        num[s]++;
      }
    }
  }
  
  int q;
  cin >> q;
  
  while (q--) {
    cin >> s >> t;
    cout << ((find(s) == find(t)) ? "yes\n" : "no\n");
  }

  return 0;
}