#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int, int *);
void ShellSort(int, int *);

int main(void) {
  int num, *arr, i, j, count = 0, maxIncrementIndex, maxIncrement;
  int *h;
  
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  h = (int *)malloc(sizeof(int) * num);

  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  
  ShellSort(num, arr, h, &maxIncrementIndex, &maxIncrement, &count);
  
  printf("%d\n", maxIncrement + 1);
  for (i = maxIncrementIndex; i != -1; i--)
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);
  printf("%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  
  free(arr);
  free(h);
  
  return 0;
}

void ShellSort(int num, int *arr, int *h, int *maxIncrementIndex, int *maxIncrement, int *count) {
  int i, j, n, m;
  h[0] = 1;
  for (i = 0; i < num; i++) {
    h[i + 1] = 3 * h[i] + 1;
    if (num < h[i + 1]) {
      *maxIncrementIndex = i;
      *maxIncrement = h[i];
      break;
    }
  }
  for (i = *maxIncrementIndex; i != -1; i--) {
    insertionSort(arr, num, h[i], count);
  }
}

void insertionSort(int *arr, int num, int h, int *count) {
  int i, j, v;
  for (i = h; i < num; i++) {
    v = arr[i];
    j = i - h;
    while (j >= 0 && arr[j] > v) {
      arr[j + h] = arr[j];
      j = j - h;
      (*count)++;
    }
    arr[j + h] = v;
  }
}