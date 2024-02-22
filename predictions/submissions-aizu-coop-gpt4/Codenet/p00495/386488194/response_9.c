#include <stdio.h>
#include <stdlib.h>

int c[5004], d[5004], m, t, u, i, f;
char buffer[10000];

int main() {
  // Use fgets instead of scanf for faster input
  fgets(buffer, sizeof(buffer), stdin);
  *c = atoi(buffer);

  // Populate c array
  for(int j = 0; j < *c; j++) {
    fgets(buffer, sizeof(buffer), stdin);
    c[j+1] = atoi(buffer);
  }

  while(fgets(buffer, sizeof(buffer), stdin) != NULL) {
    int x = atoi(buffer);
    int diff[5004];
    for (u = i = t = 0; i++ < *c; t = d[i]) {
      diff[i] = x - c[i];
      if (m < u) {
         m = u;
      }
      d[i] = diff[i] ? u : t + 1;
      u = diff[i] ? u : t + 1;
    }
  }
  printf("%d\n", m);

  return 0;
}