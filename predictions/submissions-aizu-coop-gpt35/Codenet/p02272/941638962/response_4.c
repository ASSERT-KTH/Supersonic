#include <stdio.h>
#define MAX 1000000001

void mergeSort(int *, int);
void merge(int *, int, int, int);

int main(void) {
  int n;
  scanf("%d", &n);

  int S[500000];
  for (int i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  mergeSort(S, n);

  for (int i = 0; i < n; i++) {
    printf("%d", S[i]);
    if (i != n - 1) {
      printf(" ");
    }
  }
  printf("\n");

  return 0;
}

void mergeSort(int *S, int n) {
  int temp[n];
  for (int width = 1; width < n; width *= 2) {
    for (int i = 0; i < n; i += 2 * width) {
      int left = i;
      int mid = i + width;
      int right = i + 2 * width;

      if (mid >= n) {
        continue;
      }
      if (right > n) {
        right = n;
      }

      merge(S, left, mid, right);
    }
  }
}

void merge(int *S, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  int leftPtr = left;
  int rightPtr = mid;

  int merged[right - left];

  int index = 0;
  while (leftPtr < mid && rightPtr < right) {
    if (S[leftPtr] <= S[rightPtr]) {
      merged[index++] = S[leftPtr++];
    } else {
      merged[index++] = S[rightPtr++];
    }
  }

  while (leftPtr < mid) {
    merged[index++] = S[leftPtr++];
  }
  while (rightPtr < right) {
    merged[index++] = S[rightPtr++];
  }

  for (int i = left, j = 0; i < right; i++, j++) {
    S[i] = merged[j];
  }
}