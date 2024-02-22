#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int, int *);
void ShellSort(int, int *);

int count = 0;

int main(void) {
  int num, *arr, *h, i, temp = 0;

  scanf("%d", &num);
  
  arr = (int *)malloc(sizeof(int) * num);
  h = (int *)malloc(sizeof(int) * (num + 1));
  
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);

  temp = ShellSort(num, arr);
  
  printf("%d\n", temp + 1);

  for (i = temp; i != -1; i--)
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);

  printf("%d\n", count);

  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }

  free(arr);
  free(h);

  return 0;
}

int ShellSort(int num, int *arr) {
  int i, j, n, m, temp = 0;
  h[0] = 1;
  
  for (i = 0; i < num; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  
  for (i = 0; i < num; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  
  for (i = temp; i != -1; i--) {
    insertionSort(arr, num, h[i]);
  }

  return temp;
}

void insertionSort(int *arr, int num, int h) {
  int i, j, v;
  
  for (i = h; i < num; i++) {
    v = arr[i];
    j = i - h;
    
    while (j >= 0 && arr[j] > v) {
      arr[j + h] = arr[j];
      count++;
    }
    
    j -= h;
    arr[j + h] = v;
  }
}