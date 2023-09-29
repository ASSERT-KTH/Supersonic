#include <stdio.h>
#include <stdlib.h>
#include <vector>

void insertionSort(std::vector<int>&, int, int);
void ShellSort(std::vector<int>&);
int count = 0;
std::vector<int> h(20);

int main(void) {
  int num;
  scanf("%d", &num);
  std::vector<int> arr(num);
  for (int i = 0; i < num; i++)
    scanf("%d", &arr[i]);
  ShellSort(arr);
  printf("%d\n", h.size());
  for (auto it = h.rbegin(); it != h.rend(); ++it)
    printf("%d ", *it);
  printf("\n%d\n", count);
  for (auto& e : arr) {
    printf("%d\n", e);
  }
  return 0;
}

void ShellSort(std::vector<int>& arr) {
  h[0] = 1;
  for (int i = 0; i < 19; i++) {
    h[i + 1] = 3 * h[i] + 1;
    if(h[i+1] > arr.size()) {
        h.resize(i+1);
        break;
    }
  }
  for (int i = h.size()-1; i >= 0; i--)
    insertionSort(arr, arr.size(), h[i]);
}

void insertionSort(std::vector<int>& arr, int num, int h) {
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