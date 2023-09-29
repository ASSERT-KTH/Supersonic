#include <iostream>
using namespace std;

const int MAXN = 1e5+5;
int join[MAXN], num[MAXN], s, t;

int find(int x) {
  if (x == join[x])
    return x;
  return join[x] = find(join[x]);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, q;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    join[i] = i;
    num[i] = 0;
  }

  for (int i = 1; i <= m; i++) {
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

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> s >> t;
    if (find(s) == find(t))
      cout << "yes\n";
    else
      cout << "no\n";
  }

  return 0;
}