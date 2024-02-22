#include <stdio.h>
#define MAX 1000000001

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int main(void) {
  int n;
  scanf("%d", &n);

  int S[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);

  mergesort(S, 0, n);

  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n");

  return 0;
}

void mergesort(int *S, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(S, left, mid);
    mergesort(S, mid, right);
    merge(S, left, mid, right);
  }
}

void merge(int *S, int left, int mid, int right) {
  int temp[right - left];
  int *Left = S + left;
  int *Right = S + mid;
  int *Temp = temp;

  while (Left < S + mid && Right < S + right) {
    if (*Left > *Right)
      *Temp++ = *Right++;
    else
      *Temp++ = *Left++;
  }

  while (Left < S + mid)
    *Temp++ = *Left++;

  while (Right < S + right)
    *Temp++ = *Right++;

  Temp = temp;
  int *Dest = S + left;
  while (Dest < S + right)
    *Dest++ = *Temp++;
}