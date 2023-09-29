#include <stdio.h>
#include <stdlib.h>

static int count = 0;
static int h[20];

static void insertionSort(int *arr, int num, int h) {
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

static void ShellSort(int num, int *arr) {
  int temp = 0;
  h[0] = 1;
  for (int i = 0; i < 19; i++) {
    h[i + 1] = 3 * h[i] + 1;
    if (h[i+1] > num) {
      temp = i;
      break;
    }
  }

  for (int i = temp; i >= 0; i--) {
    insertionSort(arr, num, h[i]);
  }

  printf("%d\n", temp + 1);
  for (int i = temp; i != -1; i--)
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);
  printf("%d\n", count);
}

int main(void) {
  int num;
  scanf("%d", &num);
  int *arr = (int *)malloc(sizeof(int) * num);
  for (int i = 0; i < num; i++)
    scanf("%d", &arr[i]);
    
  ShellSort(num, arr);

  for (int i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }

  free(arr);
  return 0;
}