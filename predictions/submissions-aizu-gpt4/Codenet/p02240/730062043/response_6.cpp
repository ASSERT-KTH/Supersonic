#include <iostream>
using namespace std;
int join[100000], num[100000];

int find(int x) {
  if (x != join[x])
    join[x] = find(join[x]);
  return join[x];
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m, s, t;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    join[i] = i;
    num[i] = 0;
  }
  for (int i = 0; i < m; i++) {
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
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (find(s) == find(t))
      cout << "yes\n";
    else
      cout << "no\n";
  }
}