#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, size_t, size_t *);
void ShellSort(size_t, int *);

int main(void) {
  size_t num;
  int *arr;
  scanf("%zu", &num);
  arr = (int *)calloc(num, sizeof(int));
  for (size_t i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  printf("%d\n", arr[num - 1]);
  for (size_t i = num - 2; i != -1; i--)
    printf("%d ", arr[i]);
  printf("\n");
  printf("%d\n", count);
  for (size_t i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  return 0;
}

void ShellSort(size_t num, int *arr) {
  size_t temp;
  int temp_temp;
  size_t h[20];
  h[0] = 1;
  for (size_t i = 0; i < 20; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  for (size_t i = 0; i < 20; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  for (size_t i = temp; i >= 0; i--) {
    if (i == temp) {
      temp_temp = temp;
    }
    insertionSort(arr, num, &h[i]);
  }
}

void insertionSort(int *arr, size_t num, size_t *h) {
  size_t v;
  for (size_t i = *h; i < num; i++) {
    v = arr[i];
    size_t j = i - *h;
    while (j >= 0 && arr[j] > v) {
      arr[j + *h] = arr[j];
      j -= *h;
      count++;
    }
    arr[j + *h] = v;
  }
}