#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

void insertionSort(int *, int, int);
void ShellSort(int, int *);
int count = 0;
int temp = 0;
int temp_temp;
vector<int> h;

int main(void) {
  int num, *arr, i;
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
  int i;
  h.push_back(1);
  for (i = 0; i < 20; i++) {
    h.push_back(3 * h[i] + 1);
  }
  for (i = 0; i < 20; i++) {
    if (num < h[i]) {
      temp = i - 1;
      break;
    }
  }
  temp_temp = temp;
  for (i = temp; i != -1; i--) {
    insertionSort(arr, num, h[i]);
  }
}

void insertionSort(int *arr, int num, int h) {
  int i, j, v;
  for (i = h; i < num; i++) {
    v = arr[i];
    j = i - h;
    while (j >= 0 && arr[j] > v) {
      arr[j + h] = arr[j];
      j -= h;
      count++;
    }
    arr[j + h] = v;
  }
}