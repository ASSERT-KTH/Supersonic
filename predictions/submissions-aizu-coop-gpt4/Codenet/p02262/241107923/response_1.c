#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int);
void ShellSort(int, int *);

int main(void) {
  int num, *arr, *h, i, j, temp = 0, temp_temp;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  h = (int *)malloc(sizeof(int) * (num+1));
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr, h, &temp, &temp_temp);
  printf("%d\n", temp_temp + 1);
  for (i = temp; i != -1; i--)
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  free(h);
  return 0;
}

void ShellSort(int num, int *arr, int *h, int *temp, int *temp_temp) {
  int i, j, n, m;
  h[0] = 1;
  for (i = 0; i < num; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  for (i = 0; i < num; i++) {
    if (num < h[i]) {
      *temp = i - 1;
      break;
    }
  }
  for (i = *temp; i != -1; i--) {
    if (i == *temp) {
      *temp_temp = *temp;
    }
    insertionSort(arr, num, &h[i]);
  }
}

inline void insertionSort(int *arr, int num, int *h) {
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