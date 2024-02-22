#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 100000 + 10;
const flt eps = 1e-7;

// Change the arrays to an array of structures
struct Node {
  int vw;
  int pf;
  int vf;
  int th;
} node[MAXN];

int N, pw;

// Function to calculate cost
flt calc(flt W, flt &cost) {
  cost = W * pw;

  // Loop unrolling
  for (int i = 0; i < N; i += 4) {
    for (int j = 0; j < 4 && i + j < N; ++j) {
      flt need = node[i+j].th - W * node[i+j].vw;
      if (need <= 0)
        continue;
      flt f = need / node[i+j].vf;
      cost += f * node[i+j].pf;
    }
  }

  return cost;
}

int main() {
  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &pw);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", &node[i].vw, &node[i].pf, &node[i].vf, &node[i].th);
    }

    flt left = 0, right = INT_MAX;
    flt lastC1, lastC2;
    for (int _ = 0; _ < 200; ++_) {
      flt m1 = (left + left + right) / 3.0;
      flt m2 = (left + right + right) / 3.0;
      flt c1 = calc(m1, lastC1), c2 = calc(m2, lastC2);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }

    // Use the stored result of the last calc function call
    printf("%.10f\n", min(lastC1, lastC2));
  }

  return 0;
}