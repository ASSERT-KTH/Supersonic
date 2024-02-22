#include <stdio.h>
#define MAX 1000000001

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int main(void) {
  int n, count = 0;
  scanf("%d", &n);
  int S[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);
  mergesort(S, 0, n);
  for (int i = 0; i < n; i++) {
    printf("%d%c", S[i], i != n - 1 ? ' ' : '\n');
  }
  printf("%d\n", count);
  return 0;
}

void mergesort(int *S, int left, int right) {
  if (left + 1 < right) {
    int mid = left + (right - left) / 2;
    mergesort(S, left, mid);
    mergesort(S, mid, right);
    merge(S, left, mid, right);
  }
}

void merge(int *S, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int Left[n1+1], Right[n2+1];
  int i, j, k;
  for (i = 0; i < n1; i++)
    Left[i] = S[left + i];
  for (i = 0; i < n2; i++)
    Right[i] = S[mid + i];
  Left[n1] = MAX;
  Right[n2] = MAX;
  i = 0;
  j = 0;
  int temp = Left[j] <= Right[i] ? Left[j++] : Right[i++];
  for (k = left; k < right; k++) {
    if (j < n1 && i < n2) {
      if (Left[j] <= Right[i]) S[k] = temp;
      temp = Left[j++] <= Right[i] ? Left[j] : Right[i++];
    } else if (j < n1) {
      S[k] = temp;
      temp = Left[j++];
    } else {
      S[k] = temp;
      temp = Right[i++];
    }
  }
  count += right - left;
}