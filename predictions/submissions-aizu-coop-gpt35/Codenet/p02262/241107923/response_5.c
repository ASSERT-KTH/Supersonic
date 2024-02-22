#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int);
void ShellSort(int, int *);

int main(void) {
  int num;
  int *arr;

  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  
  for (int i = 0; i < num; i++)
    scanf("%d", &arr[i]);

  ShellSort(num, arr);

  printf("%d\n", num);
  for (int i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
  
  free(arr);
  return 0;
}

void ShellSort(int num, int *arr) {
  int increments[] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161, 2391484, 7174453, 21523360, 64570081, 193710244, 581130733, 1743392200};
  int num_increments = sizeof(increments) / sizeof(increments[0]);

  for (int i = num_increments - 1; i >= 0; i--) {
    int h = increments[i];
    insertionSort(arr, num, h);
  }
}

void insertionSort(int *arr, int num, int h) {
  int count = 0;

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