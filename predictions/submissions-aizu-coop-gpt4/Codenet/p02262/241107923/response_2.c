#include <stdio.h>
#include <stdlib.h>

void ShellSort(int num, int *arr) {
  int count = 0;
  int h[20];
  h[0] = 1;
  for (int i = 0; i < 19; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }

  int temp = 0;
  for (int i = 0; i < 20; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }

  for (int i = temp; i != -1; i--) {
    int h_val = h[i];
    for (int j = h_val; j < num; j++) {
      int v = arr[j];
      int k = j - h_val;
      while (k >= 0 && arr[k] > v) {
        arr[k + h_val] = arr[k];
        k = k - h_val;
        count++;
      }
      arr[k + h_val] = v;
    }
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