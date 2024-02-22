#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int, int *);
void ShellSort(int, int *);

int main(void) {
  int num, *arr, i, j, count = 0;
  int h[20], temp, temp_temp;

  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);

  if (arr == NULL) {
    printf("Memory allocation error.\n");
    return 1;
  }

  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);

  ShellSort(num, arr, h, &temp, &temp_temp, &count);

  printf("%d\n", temp_temp + 1);

  for (i = temp; i >= 0; i--)
    printf(i == 0 ? "%d\n" : "%d ", h[i]);

  printf("%d\n", count);

  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }

  free(arr);
  return 0;
}

void ShellSort(int num, int *arr, int *h, int *temp, int *temp_temp, int *count) {
  int i, j, n, m;
  h[0] = 1;

  for (i = 0; i < 20; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }

  for (i = 0; i < 20; i++) {
    if (num < h[i]) {
      *temp = i - 1;
      break;
    }
  }

  for (i = *temp; i != -1; i--) {
    if (i == *temp) {
      *temp_temp = *temp;
    }
    insertionSort(arr, num, h[i], count);
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