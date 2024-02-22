#include <iostream>
#include <queue>
using namespace std;

void reader(int *x) {
  int k;
  scanf("%d", &k);
  *x = k;
  while (1) {
    scanf("%d", &k);
    if (k < 0 || k > 9)
      break;
    *x = ((*x) << 1) + ((*x) << 3) + k;
  }
}

int E[100000][100000];
int u[200000], v[200000], r[200000], ans[200000], d[100000], cnt = 1;
bool b[200000];
int que[100000];
int front = 0, rear = 0;

void bfs(int u, int t) {
  que[rear++] = u;
  while (front != rear) {
    int p = que[front++];
    for (int v = 0; v < 100000; v++) {
      if (E[p][v] == 1) {
        if (t) {
          if (d[v] == -1) {
            d[v] = d[p] + 1;
            cnt++;
            que[rear++] = v;
          }
        } else if (d[v] == -1) {
          d[v] = d[p] + 1;
          que[rear++] = v;
        }
      }
    }
  }
}

int main() {
  int n, m, q;
  reader(&n);
  reader(&m);
  reader(&q);
  for (int i = 0; i < m; i++) {
    reader(&u[i]);
    reader(&v[i]);
    u[i]--;
    v[i]--;
    E[u[i]][v[i]] = 1;
    E[v[i]][u[i]] = 1;
  }
  memset(d, -1, sizeof(d));
  d[0] = 0;
  bfs(0, 0);
  for (int i = 0; i < m; i++) {
    if (d[u[i]] > d[v[i]])
      swap(u[i], v[i]);
  }
  for (int i = 0; i < q; i++) {
    reader(&r[i]);
    r[i]--;
    b[r[i]] = true;
  }
  for (int i = 0; i < m; i++) {
    if (!b[i]) {
      if (d[v[i]] - d[u[i]] == 1) {
        E[u[i]][v[i]] = 1;
      }
    }
  }
  bfs(0, 1);
  for (int i = q - 1; i >= 0; i--) {
    ans[i] = n - cnt;
    if (d[v[r[i]]] - d[u[r[i]]] == 1 && d[u[r[i]]] == 0) {
      E[u[r[i]]][v[r[i]]] = 1;
      cnt++;
      bfs(v[r[i]], 1);
    }
  }
  for (int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}