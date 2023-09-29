#include <stdio.h>
#define MAX 10000
#define NIL -1

int n, S[MAX], q, T[MAX], C = 0;
int H[MAX];

void read(){
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
    H[S[i]] = i;
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
    if ( H[T[i]] != NIL ) C++;
  }
}

int main(){
  int i;
  for (i = 0; i < MAX; i++) H[i] = NIL;
  read();
  printf("%d\n", C);
  return 0;
}