#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int *);
void ShellSort(int, int *);

int count = 0;
int temp = 0;
int temp_temp;
int h[20];

int main(void) {
  int num, *arr, i, j;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++) {
    scanf("%d", &arr[i]);
  }
  ShellSort(num, arr);
  printf("%d\n", temp_temp + 1);
  for (i = temp; i != -1; i--) {
    if (i == 0) {
      printf("%d\n", h[i]);
    } else {
      printf("%d ", h[i]);
    }
  }
  printf("%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  int i, j, n, m;
  h[0] = 1;
  for (i = 0; i < 20; i++) {
    h[i + 1] = 3 * h[i] + 1;
    if (h[i + 1] > (num / 3)) {
      temp = i;
      break;
    }
  }
  for (i = temp; i >= 0; i--) {
    if (i == temp) {
      temp_temp = temp;
    }
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
      count++;
    }
    arr[j + (*h)] = v;
  }
}