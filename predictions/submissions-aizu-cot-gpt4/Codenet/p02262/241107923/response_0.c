#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int *, int *);
int ShellSort(int, int *);

int main(void) {
  int num, *arr, i, j, count = 0, temp;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  temp = ShellSort(num, arr);
  printf("%d\n", temp + 1);
  printf("%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  return 0;
}

int ShellSort(int num, int *arr) {
  int i, j, n, m, temp;
  int *h = malloc(sizeof(int) * num);
  h[0] = 1;
  for (i = 0; i < num; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  for (i = 0; i < num; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  insertionSort(arr, num, &h[temp], &count);
  free(h);
  return temp;
}

void insertionSort(int *arr, int num, int *h, int *count) {
  int i, j, v;
  for (i = (*h); i < num; i++) {
    v = arr[i];
    j = i - (*h);
    while (j >= 0 && arr[j] > v) {
      arr[j + (*h)] = arr[j];
      j = j - (*h);
      (*count)++;
    }
    arr[j + (*h)] = v;
  }
}