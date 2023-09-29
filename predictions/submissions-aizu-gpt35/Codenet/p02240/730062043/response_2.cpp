#include <iostream>
using namespace std;
const int MAXN = 100000;
int join[MAXN], num[MAXN];
int find(int x) {
  if (x == join[x])
    return x;
  return join[x] = find(join[x]);
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, s, t;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    join[i] = i;
  }
  for (int i = 0; i < m; i++) {
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
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (find(s) == find(t))
      cout << "yes\n";
    else
      cout << "no\n";
  }
}