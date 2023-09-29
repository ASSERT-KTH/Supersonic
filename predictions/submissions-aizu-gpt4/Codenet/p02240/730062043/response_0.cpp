#include <iostream>
#include <vector>
using namespace std;

vector<int> join, num;

int find(int x) {
  return (x == join[x]) ? x : (join[x] = find(join[x]));
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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