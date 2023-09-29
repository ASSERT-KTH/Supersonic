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
  printf("%d\n", count);
  for (int i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  h[0] = 1;
  for (int i = 0; i < 20; i++) {
    h[i + 1] = 3 * h[i] + 1;
    if(num < h[i + 1]){
      break;
    }
  }
  for (int i = 19; i >= 0; i--) {
    if(h[i] <= num){
      insertionSort(arr, num, h[i]);
    }
  }
}

void insertionSort(int *arr, int num, int h) {
  for (int i = h; i < num; i++) {
    int v = arr[i];
    int j = i - h;
    while (j >= 0 && arr[j] > v) {
      arr[j + h] = arr[j];
      j = j - h;
      count++;
    }
    arr[j + h] = v;
  }
}