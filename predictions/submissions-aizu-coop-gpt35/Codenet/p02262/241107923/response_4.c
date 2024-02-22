#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int *);
void ShellSort(int, int *);

int count = 0;

int main(void) {
  int num, *arr, i;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  printf("%d\n", num);
  for (i = num - 1; i >= 0; i--) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  int i, j, n, m;
  int *h = (int *)malloc(sizeof(int) * num);
  h[0] = 1;
  for (i = 0; h[i] < num; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  for (i = i - 1; i >= 0; i--) {
    insertionSort(arr, num, &h[i]);
  }
  free(h);
}

void insertionSort(int *arr, int num, int *h) {
  int i, j, v;
  for (i = (*h); i < num; i++) {
    v = arr[i];
    j = i - (*h);
    while (j >= 0 && arr[j] > v) {
      arr[j + (*h)] = arr[j];
      j = j - (*h);
      count++;
    }
    arr[j + (*h)] = v;
  }
}