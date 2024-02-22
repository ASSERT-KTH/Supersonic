#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int *);
void ShellSort(int, int *);

int main(void) {
  int num, *arr, i;
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
  int *h;

  int max_h = 1;
  while (max_h <= num / 3)
    max_h = 3 * max_h + 1;

  h = (int *)malloc(sizeof(int) * max_h);

  temp = (max_h - 1) / 3;
  temp_temp = temp;

  for (i = 0; i < temp_temp; i++)
    h[i] = max_h = (max_h - 1) / 3;
  h[temp_temp] = 1;

  for (i = temp_temp; i >= 0; i--)
    insertionSort(arr, num, &h[i]);

  free(h);
}

void insertionSort(int *arr, int num, int *h) {
  int i, j, v, count = 0;
  for (i = *h; i < num; i++) {
    v = arr[i];
    j = i - *h;
    while (j >= 0 && arr[j] > v) {
      arr[j + *h] = arr[j];
      j = j - *h;
      count++;
    }
    arr[j + *h] = v;
  }
}