#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int, int *);
void ShellSort(int, int *);

int main(void) {
  int num, *arr, i, j, count = 0;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr, &count);
  printf("%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}

void ShellSort(int num, int *arr, int *count) {
  int i, temp = 0, h = 1;
  while (h < num) {
    h = 3 * h + 1;
  }
  for (i = h; i > 0; i /= 3) {
    insertionSort(arr, num, i, count);
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