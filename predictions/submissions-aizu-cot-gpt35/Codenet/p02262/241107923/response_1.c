#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int *);
void ShellSort(int, int *);

int main(void) {
  int num, *arr, i, j;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  printf("%d\n", arr[0]);
  for (i = 1; i < num; i++)
    printf("%d ", arr[i]);
  printf("\n");
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  int i, j, n, m, temp, temp_temp;
  int* h;
  h = (int *)malloc(sizeof(int) * 20);
  h[0] = 1;
  for (i = 0; i < 20; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  int temp = -1;
  for (i = 0; i < 20; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  for (i = temp; i >= 0; i--) {
    if (i == temp) {
      temp_temp = temp;
    }
    insertionSort(arr, num, &h[i]);
  }
  free(h);
}

void insertionSort(int *arr, int num, int *h) {
  int i, j, v, shifts;
  for (i = (*h); i < num; i++) {
    v = arr[i];
    j = i - (*h);
    shifts = 0;
    while (j >= 0 && arr[j] > v) {
      arr[j + (*h)] = arr[j];
      j -= (*h);
      shifts++;
    }
    arr[j + (*h)] = v;
    count += shifts;
  }
}