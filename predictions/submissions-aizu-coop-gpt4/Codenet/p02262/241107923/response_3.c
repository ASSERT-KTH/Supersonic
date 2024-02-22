#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int);
void ShellSort(int, int *);
void printArray(int *, int);

int main(void) {
  int num, *arr, i;

  scanf("%d", &num);
  arr = (int *)malloc(sizeof(int) * num);
  
  for (i = 0; i < num; i++)
    scanf("%d", &arr[i]);
    
  ShellSort(num, arr);
  
  printArray(arr, num);
  
  return 0;
}

void ShellSort(int num, int *arr) {
  int i, gapSequence[20], maxGapIndex;
  
  gapSequence[0] = 1;
  
  for (i = 0; i < 19; i++) // Generate gap sequence
    gapSequence[i + 1] = 3 * gapSequence[i] + 1;
    
  for (i = 0; i < 20; i++) {
    if (num < gapSequence[i]) {
      maxGapIndex = i - 1;
      break;
    }
  }
  
  printf("%d\n", maxGapIndex + 1);
  
  for (i = maxGapIndex; i >= 0; i--)
    insertionSort(arr, num, gapSequence[i]);
}

void insertionSort(int *arr, int num, int h) {
  int i, j, v, count = 0;
  
  for (i = h; i < num; i++) {
    v = arr[i];
    j = i - h;
    
    while (j >= 0 && arr[j] > v) {
      arr[j + h] = arr[j];
      j = j - h;
      count++;
    }
    arr[j + h] = v;
  }
  
  printf("%d\n", count);
}

void printArray(int *arr, int num) {
  int i;
  
  for (i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
}