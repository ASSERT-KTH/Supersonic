#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int *);

void ShellSort(int, int *);

int main(void) {
  int num, arr[1000], i, j;
  scanf("%d", &num);

  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);

  ShellSort(num, arr);

  printf("%d\n", arr[0]);
  for (i = 1; i < num; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}

void ShellSort(int num, int *arr) {
  int i, j, n, m;
  int h[20];

  h[0] = 1;
  for (i = 0; i < 20; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }

  for (i = 0; i < 20; i++) {
    if (num < h[i]) {
      break;
    }
  }

  for (i = i - 1; i >= 0; i--) {
    insertionSort(arr, num, &h[i]);
  }
}

void insertionSort(int *arr, int num, int *h) {
  int i, j, v;
  for (i = (*h); i < num; i++) {
    v = arr[i];
    j = i - (*h);
    while (j >= 0 && arr[j] > v) {
      arr[j + (*h)] = arr[j];
      j = j - (*h);
    }
    arr[j + (*h)] = v;
  }
}