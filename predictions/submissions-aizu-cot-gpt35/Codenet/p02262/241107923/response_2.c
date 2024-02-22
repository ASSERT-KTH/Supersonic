#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int num, int h);
void ShellSort(int num, int *arr);

int main(void) {
  int num, *arr, i;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  printf("%d\n", num);
  for (i = num - 1; i >= 0; i--)
    i == 0 ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  int i, j, n, m, temp, temp_temp;
  int *h;
  h = (int *)malloc(sizeof(int) * num); // Allocate dynamically based on num
  h[0] = 1;
  for (i = 0; i < num; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  temp = 0;
  for (i = 0; i < num; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  temp_temp = temp;
  for (i = temp; i != -1; i--) {
    insertionSort(arr, num, h[i]);
  }
  free(h);
}

void insertionSort(int *arr, int num, int h) {
  int i, j, v;
  for (i = h; i < num; i++) {
    v = arr[i];
    j = i - h;
    while (j >= 0 && arr[j] > v) {
      arr[j + h] = arr[j];
      j = j - h;
    }
    arr[j + h] = v;
  }
}