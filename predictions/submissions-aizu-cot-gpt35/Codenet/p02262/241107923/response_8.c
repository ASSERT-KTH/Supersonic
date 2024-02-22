#include <stdio.h>

void insertionSort(int *arr, int num, int h);
void ShellSort(int num, int *arr);

int main(void) {
  int num;
  scanf("%d", &num);
  int arr[num];
  for (int i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  printf("%d\n", temp + 1);
  for (int i = temp; i != -1; i--)
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);
  printf("%d\n", count);
  for (int i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}

void ShellSort(int num, int *arr) {
  int h[20];
  h[0] = 1;
  int temp;
  for (int i = 0; i < 20; i++) {
    h[i + 1] = (h[i] - 1) / 3;
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  for (int i = temp; i != -1; i--) {
    insertionSort(arr, num, h[i]);
  }
}

void insertionSort(int *arr, int num, int h) {
  int count = 0;
  for (int i = h; i < num; i++) {
    int v = arr[i];
    int j = i - h;
    while (j >= 0 && arr[j] > v) {
      arr[j + h] = arr[j];
      j -= h;
      count++;
    }
    arr[j + h] = v;
  }
}