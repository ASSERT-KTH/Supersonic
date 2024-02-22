#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int);
void ShellSort(int, int *);

int main(void) {
  int num, *arr, i;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  int i, j, h, temp, temp_temp;
  int *h_array;
  h_array = (int *)malloc(sizeof(int) * num);
  h_array[0] = 1;

  for (i = 0; i < num; i++) {
    h_array[i + 1] = 3 * h_array[i] + 1;
  }

  for (i = 0; i < num; i++) {
    if (num < h_array[i]) {
      temp = i - 1;
      break;
    }
  }

  temp_temp = temp;

  for (i = temp; i != -1; i--) {
    h = h_array[i];
    for (j = h; j < num; j++) {
      int v = arr[j];
      int k = j - h;
      while (k >= 0 && arr[k] > v) {
        arr[k + h] = arr[k];
        k = k - h;
      }
      arr[k + h] = v;
    }
  }

  printf("%d\n", temp_temp + 1);
  for (i = temp; i != -1; i--)
    i == 0 ? printf("%d\n", h_array[i]) : printf("%d ", h_array[i]);
  printf("%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }

  free(h_array);
}