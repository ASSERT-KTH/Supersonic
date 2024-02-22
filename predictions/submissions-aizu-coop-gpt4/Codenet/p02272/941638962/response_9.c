#include <stdio.h>
#define MAX 1000000001
void mergesort(int *, int, int, int *);
void merge(int *, int, int, int, int *);
int count = 0, n;

int main(void) {
  int S[500000];
  int Temp[500000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  mergesort(S, 0, n, Temp);
  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n%d\n", count);
  return 0;
}

void mergesort(int *S, int left, int right, int *Temp) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(S, left, mid, Temp);
    mergesort(S, mid, right, Temp);
    merge(S, left, mid, right, Temp);
  }
}

void merge(int *S, int left, int mid, int right, int *Temp) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++)
    Temp[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    Temp[n1+i] = S[mid + i];
  int i = 0, j = n1, k = left;
  while (k < right) {
    if (j >= right || (i < n1 && Temp[i] <= Temp[j]))
      S[k++] = Temp[i++];
    else
      S[k++] = Temp[j++];
  }
  count += right - left;
}