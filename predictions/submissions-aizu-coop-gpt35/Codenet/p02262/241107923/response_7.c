#include <stdio.h>
#include <math.h>

void insertionSort(int *arr, int num, int *h);
void ShellSort(int num, int *arr, int *h);

int main(void) {
  int num, i;
  scanf("%d", &num);
  int arr[num];
  for (i = 0; i < num; i++) {
    scanf("%d", &arr[i]);
  }
  int h[20];
  ShellSort(num, arr, h);
  printf("%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}

void ShellSort(int num, int *arr, int *h) {
  int i, j, temp, temp_temp;
  h[0] = 1;
  for (i = 1; i < 20; i++) {
    h[i] = (pow(4, i) + 3 * pow(2, i - 1) + 1) / 2;
  }
  int temp = -1;
  for (i = 0; i < 20; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  int temp_temp = temp;
  for (i = temp; i != -1; i--) {
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