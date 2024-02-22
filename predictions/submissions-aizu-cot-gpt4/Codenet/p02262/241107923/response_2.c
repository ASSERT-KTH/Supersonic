#include <stdio.h>
#include <vector>

void insertionSort(int *, int, int, int&);
void ShellSort(int, int *);

int main(void) {
  int num, *arr;
  scanf("%d", &num);
  arr = new int[num];
  for (int i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(num, arr);
  delete[] arr;
  return 0;
}

// Pre-calculated values for the 'h' array
int h[20] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161, 2391484, 7174453, 21523360, 64570081, 193710244, 581130733, 1743392200};

void ShellSort(int num, int *arr) {
  int temp, count=0;
  for (temp = 0; temp < 20; temp++) {
    if (num < h[temp]) {
      temp--;
      break;
    }
  }
  printf("%d\n", temp + 1);
  for (int i = temp; i != -1; i--) {
    i == 0 ? printf("%d\n", h[i]) : printf("%d ", h[i]);
    insertionSort(arr, num, h[i], count);
  }
  printf("%d\n", count);
  for (int i = 0; i < num; i++) {
    printf("%d\n", arr[i]);
  }
}

void insertionSort(int *arr, int num, int h, int& count) {
  int j, v;
  for (int i = h; i < num; i++) {
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