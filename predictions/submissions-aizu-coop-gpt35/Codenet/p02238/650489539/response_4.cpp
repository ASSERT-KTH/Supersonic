#include <iostream>
#include <stack>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int** G;
int* color;
int n;
int* d;
int* f;
int t;

void search_loop(int start) {
  stack<int> st;
  st.push(start);

  while (!st.empty()) {
    int i = st.top();
    st.pop();

    if (color[i] != WHITE) {
      continue;
    }

    d[i] = ++t;
    color[i] = GRAY;

    for (int next = 1; next <= n; next++) {
      if (G[i][next] > 0 && color[next] == WHITE) {
        st.push(next);
      }
    }

    f[i] = ++t;
    color[i] = BLACK;
  }
}

void dfs() {
  for (int i = 1; i <= n; i++) {
    color[i] = WHITE;
  }

  t = 0;

  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE) {
      search_loop(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  cin >> n;

  G = new int*[n + 1];
  for (int i = 1; i <= n; i++) {
    G[i] = new int[n + 1];
    for (int j = 1; j <= n; j++) {
      G[i][j] = 0;
    }
  }

  int i, e, k, j;
  do {
    cin >> i >> e;
    for (j = 1; j <= e; j++) {
      cin >> k;
      G[i][k] = 1;
    }
  } while (i < n);

  color = new int[n + 1];
  d = new int[n + 1];
  f = new int[n + 1];

  dfs();

  for (int i = 1; i <= n; i++) {
    delete[] G[i];
  }
  delete[] G;
  delete[] color;
  delete[] d;
  delete[] f;

  return 0;
}