#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int, int, int *);
void ShellSort(int, int *, int *, int *, int *);

int main(void) {
  int num, *arr, i, j, count = 0, temp = 0, temp_temp;
  int h[20];

  num = getchar_unlocked() - '0';
  
  arr = (int *)malloc(sizeof(int) * num);
  
  for (i = 0; i < num; i++)
    arr[i] = getchar_unlocked() - '0';
  
  ShellSort(num, arr, h, &temp, &count);
  
  putchar_unlocked(temp_temp + 1 + '0');
  putchar_unlocked('\n');
  
  for (i = temp; i != -1; i--) {
    putchar_unlocked(h[i] + '0');
    i == 0 ? putchar_unlocked('\n') : putchar_unlocked(' ');
  }
  
  putchar_unlocked(count + '0');
  putchar_unlocked('\n');
  
  for (i = 0; i < num; i++) {
    putchar_unlocked(arr[i] + '0');
    putchar_unlocked('\n');
  }
  
  free(arr);
  
  return 0;
}

void ShellSort(int num, int *arr, int *h, int *temp, int *count) {
  int i, j, n, m;
  h[0] = 1;
  
  for (i = 0; i < 20; i++) {
    h[i + 1] = 3 * h[i] + 1;
  }
  
  for (i = 0; i < 20; i++) {
    if (num < h[i]) {
      *temp = i - 1;
      break;
    }
  }
  
  for (i = *temp; i != -1; i--) {
    insertionSort(arr, num, h[i], count);
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