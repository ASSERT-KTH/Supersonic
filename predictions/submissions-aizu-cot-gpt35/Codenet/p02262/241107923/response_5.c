#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int, int *);
void ShellSort(int, int *);

int main(void) {
  int num;
  scanf("%d", &num);
  int *arr = (int *)malloc(sizeof(int) * num);
  for (int i = 0; i < num; i++) {
    scanf("%d", &arr[i]);
  }
  ShellSort(num, arr);
  printf("%d\n", arr[num - 1] + 1);
  for (int i = num - 1; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  int h[20];
  h[0] = 1;
  for (int i = 0; i < 20; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  int temp = 0;
  for (int i = 0; i < 20; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  int count = 0;
  for (int i = temp; i >= 0; i--) {
    insertionSort(arr, num, h[i], &count);
  }
}

void insertionSort(int *arr, int num, int h, int *count) {
  for (int i = h; i < num; i++) {
    int v = arr[i];
    int j = i - h;
    while (j >= 0 && arr[j] > v) {
      arr[j + h] = arr[j];
      j = j - h;
      (*count)++;
    }
    arr[j + h] = v;
  }
}