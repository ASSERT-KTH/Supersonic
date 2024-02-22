#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int, int *);
void ShellSort(int, int *, int *, int *, int **);

int main(void) {
  int num, *arr, *h, count = 0, temp = 0, temp_temp;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  h = (int *)malloc(sizeof(int) * (num + 1));
  for (int i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr, &temp, &temp_temp, &h);
  printf("%d\n", temp_temp + 1);
  for (int i = temp; i != -1; i--)
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);
  printf("%d\n", count);
  for (int i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  free(h);
  return 0;
}

void ShellSort(int num, int *arr, int *temp, int *temp_temp, int **h) {
  (*h)[0] = 1;
  for (int i = 0; i < num; i++) {
    (*h)[i + 1] = 3 * (*h)[i] + 1;
  }
  for (int i = 0; i < num; i++) {
    if (num < (*h)[i]) {
      *temp = i - 1;
      break;
    }
  }
  for (int i = *temp; i != -1; i--) {
    if (i == *temp) {
      *temp_temp = *temp;
    }
    int count = 0;
    insertionSort(arr, num, (*h)[i], &count);
  }
}

void insertionSort(int *arr, int num, int h, int *count) {
  int v, j;
  for (int i = h; i < num; i++) {
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