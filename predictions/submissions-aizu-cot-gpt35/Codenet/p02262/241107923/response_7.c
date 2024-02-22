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
  printf("%d\n", temp_temp + 1);
  for (i = temp; i != -1; i--)
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);
  printf("%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  int i, j, gap, temp_temp;
  int h[20];
  
  h[0] = 1;
  for (i = 1; ; i++) {
    h[i] = 3 * h[i - 1] + 1;
    if (h[i] >= num) {
      temp_temp = i - 1;
      break;
    }
  }
  
  for (i = temp_temp; i >= 0; i--) {
    insertionSort(arr, num, h[i]);
  }
}

void insertionSort(int *arr, int num, int h) {
  int i, j, value, count = 0;
  for (i = h; i < num; i++) {
    value = arr[i];
    j = i - h;
    while (j >= 0 && arr[j] > value) {
      arr[j + h] = arr[j];
      j = j - h;
      count++;
    }
    arr[j + h] = value;
  }
}