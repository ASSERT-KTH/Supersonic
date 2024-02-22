#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int find(vector<int>& join, int x) {
  if (x == join[x])
    return x;
  return find(join, join[x]);
}

int main() {
  int n, m, s, t;
  cin >> n >> m;

  vector<int> join(n);
  vector<int> num(n);
  unordered_map<int, int> counts;
  unordered_set<int> uniqueElements;

  join.reserve(n);
  num.reserve(n);
  counts.reserve(n);
  uniqueElements.reserve(n);

  for (int i = 0; i < n; i++) {
    join[i] = i;
  }

  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    s = find(join, s);
    t = find(join, t);
    if (s != t) {
      if (counts[s] < counts[t])
        join[s] = join[t];
      else {
        join[t] = join[s];
        if (counts[s] == counts[t])
          counts[s]++;
      }
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    int sParent = find(join, s);
    int tParent = find(join, t);
    if (sParent == tParent)
      cout << "yes\n";
    else
      cout << "no\n";
  }

  return 0;
}