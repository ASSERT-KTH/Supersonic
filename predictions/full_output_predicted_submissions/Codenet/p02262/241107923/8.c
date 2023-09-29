#include <stdio.h>
#include <stdlib.h>
void insertionSort(int *, int, int *);
void ShellSort(int, int *);
int count = 0;
int temp = 0;
int temp_temp;
int h[19];
int main(void) {
  int num, *arr, i, j;
  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  printf("%d\n", temp_temp + 1);
  for (i = temp; i != -1; i--)
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);
  printf("%d\n", count);
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}
void ShellSort(int num, int *arr) {
  int i, j, n, m;
  h[0] = 1;
  for (i = 0; i < 20; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  for (i = 0; i < 20; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  for (i = temp; i != -1; i--) {
    if (i == temp) {
      temp_temp = temp;
    }
    insertionSort(arr, num, &h[i]);
  }
}
void insertionSort(int *arr, int num, int *h) {
  int i, j, v;
  for (i = (*h); i < num; i++) {
    v = arr[i];
   