#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int, int*);
void ShellSort(int, int *, int*, int*);

int main(void) {
  int num, *arr, i, j;
  int h[20];
  int count = 0;
  int temp = 0;

  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);

  ShellSort(num, arr, h, &temp);

  printf("%d\n", temp + 1);
  for (i = temp; i != -1; i--)
    printf("%d ", h[i]);
  printf("\n%d\n", count);

  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}

void ShellSort(int num, int *arr, int *h, int *temp) {
  int i, j, n, m;
  h[0] = 1;
  for (i = 0; h[i] < num; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  *temp = i - 1;
  for (i = *temp; i != -1; i--) {
    insertionSort(arr, num, h[i], temp);
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