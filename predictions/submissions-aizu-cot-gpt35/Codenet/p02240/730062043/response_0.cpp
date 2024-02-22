#include <cstdio>

int find(int join[], int x) {
  if (x == join[x])
    return x;
  return join[x] = find(join, join[x]);
}

int main() {
  int n, m, s, t;
  scanf("%d %d", &n, &m);
  
  int* join = new int[n];
  int* num = new int[n]();
  
  for (int i = 0; i < n; i++) {
    join[i] = i;
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
  
  delete[] join;
  delete[] num;
  
  return 0;
}