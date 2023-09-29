#include <iostream>
using namespace std;
int find(int join[], int x) {
  if (x == join[x])
    return x;
  return find(join, join[x]);
}
int main(int argc, char *argv[]) {
  int n, m, join[100000], num[100000], s, t;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    join[i] = i;
    num[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &s, &t);
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
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &s, &t);
    if (find(join, s) == find(join, t))
      printf("yes\n");
    else
      printf("no\n");
  }
}
