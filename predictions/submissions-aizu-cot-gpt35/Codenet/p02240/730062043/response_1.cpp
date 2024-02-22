#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& join, int x) {
  while (x != join[x])
    x = join[x];
  return x;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  
  int n, m, s, t;
  cin >> n >> m;

  vector<int> join(n), num(n, 0);
  for (int i = 0; i < n; i++) {
    join[i] = i;
  }

  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    s = find(join, s);
    t = find(join, t);
    if (s != t) {
      if (num[s] < num[t]) {
        join[s] = join[t];
      } else {
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