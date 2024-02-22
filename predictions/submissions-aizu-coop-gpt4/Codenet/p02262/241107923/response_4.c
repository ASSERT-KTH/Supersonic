#include <stdio.h>

#define MAX_N 1000 // Maximum size of array

void insertionSort(int *, int, int, int *);
void ShellSort(int, int *);

int main(void) {
  int num, arr[MAX_N], i;
  int count = 0;
  int temp = 0;
  int temp_temp;
  int h[20];

  scanf("%d", &num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  printf("%d\n", temp_temp + 1);
  for (i = temp; i >= 0; i--)
    printf("%d ", h[i]);
  printf("\n%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}

void ShellSort(int num, int *arr) {
  int i, j, n, m;
  int temp = 0;
  int temp_temp;
  int h[20];

  h[0] = 1;
  for (i = 0; i < 20; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  for (i = 0; i < 20; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  temp_temp = temp;
  for (i = temp; i >= 0; i--) {
    insertionSort(arr, num, h[i], &count);
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