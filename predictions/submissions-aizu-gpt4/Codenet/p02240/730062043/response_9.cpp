#include <iostream>
using namespace std;
int find(int join[], int x) {
  return (x == join[x]) ? x : (join[x] = find(join, join[x]));
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  int n, m, join[100000], num[100000], s, t;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    join[i] = i;
    num[i] = 0;
  }
  while(m--) {
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
  while(q--) {
    cin >> s >> t;
    if (find(join, s) == find(join, t))
      cout << "yes\n";
    else
      cout << "no\n";
  }
}