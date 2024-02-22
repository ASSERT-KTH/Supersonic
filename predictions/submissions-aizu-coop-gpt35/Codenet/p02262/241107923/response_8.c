#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insertionSort(int *, int, int *);
void ShellSort(int, int *);

int main(void) {
  int num, *arr, i, j;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  printf("%d\n", temp_temp + 1);
  for (i = temp; i != -1; i--)
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}

void ShellSort(int num, int *arr) {
  int i, j, n, m;
  int max_gaps = (int)(log(num) / log(3));
  int* h = (int*)malloc(sizeof(int) * max_gaps);
  
  h[0] = 1;
  for (i = 0; i < max_gaps; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  
  int temp = -1;
  for (i = max_gaps - 1; i >= 0; i--) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  
  int temp_temp = temp;
  for (i = temp; i != -1; i--) {
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
    }
    arr[j + (*h)] = v;
  }
}