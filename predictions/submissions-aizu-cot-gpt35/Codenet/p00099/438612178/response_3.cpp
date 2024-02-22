#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
int S[MAX];
int maxScore[MAX];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    maxScore[a] = max(maxScore[a], S[a]);
    printf("%d %d\n", a, maxScore[a]);
  }

  return 0;
}