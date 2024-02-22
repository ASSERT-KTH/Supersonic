#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int);
void ShellSort(int, int *);

int main(void) {
  int num, *arr, i;
  scanf("%d", &num);
  arr = (int *)calloc(num, sizeof(int));
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  int i, temp = 0;
  int h[21] = {1};
  for (i = 0; i < 20; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
    h[i + 1] = 3 * h[i] + 1;
  }
  for (i = temp; i != -1; i--) {
    insertionSort(arr, num, h[i]);
  }
}

void insertionSort(int *arr, int num, int h) {
  int i, j, v;
  int count = 0;
  for (i = h; i < num; i++) {
    v = arr[i];
    j = i - h;
    while (j >= 0 && arr[j] > v) {
      arr[j + h] = arr[j];
      j = j - h;
      count++;
    }
    arr[j + h] = v;
  }
  printf("%d\n", count);
}