#include <stdio.h>
#include <stdlib.h>

// Removed global variables.

void insertionSort(int *, int, int, int *);
void ShellSort(int, int *, int *);

int main(void) {
  int num, *arr, i, j;
  int temp = 0;
  int temp_temp;
  int count = 0;
  int h[20] = {1}; // Initialized first element to 1.

  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  
  ShellSort(num, arr, h);
  
  printf("%d\n", temp_temp + 1);
  for (i = temp; i >= 0; i--)
    printf("%d ", h[i]);
  printf("\n%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }

  free(arr); // Freed allocated memory.
  
  return 0;
}

void ShellSort(int num, int *arr, int *h) {
  int i, j, n, m;
  int temp = 0;
  int temp_temp;
  
  // Dynamically calculate the gap sequence.
  for (i = 0; h[i] < num; i++) {
    h[i + 1] = 3 * h[i] + 1;
    temp = i;
  }
  
  temp_temp = temp; // No need to put this inside the loop.
  
  for (; temp >= 0; temp--) {
    insertionSort(arr, num, h[temp], &count);
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