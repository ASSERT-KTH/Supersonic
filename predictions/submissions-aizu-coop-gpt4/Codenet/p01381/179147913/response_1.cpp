#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n, k;
  while (cin >> n >> k) {
    if (n / 2 < k) {
      printf("-1\n");
      continue;
    }
    int* p = new int[n + 2]; // heap allocation
    p[0] = 0;
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    int** precomputedValues = new int*[n-1]; // precomputing
    for (int j = 0; j < n - 1; j++) {
      precomputedValues[j] = new int[2];
      precomputedValues[j][0] = (p[j] + 1) % n + 1;
      precomputedValues[j][1] = (p[j + 1] + 1) % n + 1;
    }
    for (int i = 0; i < k; i++) {
      if (i != 0)
        printf("\n");
      for (int j = 0; j < n - 1; j++) {
        printf("%d %d\n", precomputedValues[j][0], precomputedValues[j][1]);
      }
    }
    delete[] p; // free memory
    for(int i = 0; i < n-1; i++){
      delete[] precomputedValues[i];
    }
    delete[] precomputedValues;
  }
}