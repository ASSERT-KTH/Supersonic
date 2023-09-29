#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int);
void ShellSort(int, int *);

int count = 0;
int h[20];

int main(void) {
  int num, *arr;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (int i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  for (int i = 0; i < num; i++)
    printf("%d\n", arr[i]);
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  h[0] = 1;
  for (int i = 0; h[i] <= num; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  for (int gap = h[count]; gap > 0; gap = h[--count]) {
    insertionSort(arr, num, gap);
  }
}

void insertionSort(int *arr, int num, int gap) {
  for (int i = gap; i < num; i++) {
    int v = arr[i];
    int j = i - gap;
    while (j >= 0 && arr[j] > v) {
      arr[j + gap] = arr[j];
      j -= gap;
    }
    arr[j + gap] = v;
  }
}