#include <stdio.h>
#include <stdlib.h>

void ShellSort(int num, int *arr);
void insertionSort(int *arr, int num, int h);

int main(void) {
  int num, *arr, i;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  int i, j, h, count = 0;
  int temp = 0, temp_temp;
  int h[20];

  // Generate Sedgewick sequence
  h[0] = 1;
  for (i = 0; i < 20; i++) {
    h[i + 1] = 9 * (1 << i) - 9 * (1 << (i / 2)) + 1;
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }

  for (i = temp; i >= 0; i--) {
    if (i == temp) {
      temp_temp = temp;
    }
    insertionSort(arr, num, h[i]);
  }

  printf("%d\n", temp_temp + 1);
  for (i = temp; i >= 0; i--)
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);
  printf("%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
}

void insertionSort(int *arr, int num, int h) {
  int i, j, v;
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
}