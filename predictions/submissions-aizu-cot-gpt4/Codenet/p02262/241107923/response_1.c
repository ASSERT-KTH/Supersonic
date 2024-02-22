#include <stdio.h>
#define MAX_SIZE 10000

void ShellSort(int num, int *arr, int &count, int *h, int &temp, int &temp_temp);
void insertionSort(int *arr, int num, int *h, int &count);

int main(void) {
  int num, arr[MAX_SIZE], i, count = 0, h[20], temp = 0, temp_temp;
  scanf("%d", &num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr, count, h, temp, temp_temp);
  printf("%d\n", temp_temp + 1);
  for (i = temp; i != -1; i--)
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);
  printf("%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}

inline void ShellSort(int num, int *arr, int &count, int *h, int &temp, int &temp_temp) {
  int i;
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
  for (i = temp; i != -1; i--) {
    if (i == temp) {
      temp_temp = temp;
    }
    insertionSort(arr, num, &h[i], count);
  }
}

inline void insertionSort(int *arr, int num, int *h, int &count) {
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