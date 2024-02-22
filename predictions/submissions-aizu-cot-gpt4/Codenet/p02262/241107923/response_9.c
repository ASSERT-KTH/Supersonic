#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr, int h) {
  int count = 0;
  for (int i = h; i < arr.size(); i++) {
    int v = arr[i];
    int j = i - h;
    while (j >= 0 && arr[j] > v) {
      arr[j + h] = arr[j];
      j = j - h;
      count++;
    }
    arr[j + h] = v;
  }
  std::cout << count << std::endl;
}

void ShellSort(int num, std::vector<int>& arr) {
  std::vector<int> h(num);
  h[0] = 1;
  for (int i = 0; i < num; i++) {
    h[i + 1] = 3 * h[i] + 1;
    if (num < h[i]) {
      int temp = i - 1;
      for (int i = temp; i != -1; i--) {
        insertionSort(arr, h[i]);
      }
      break;
    }
  }
}

int main() {
  int num;
  std::cin >> num;
  std::vector<int> arr(num);
  for (int& element : arr)
    std::cin >> element;
  ShellSort(num, arr);
  for (const int& element : arr)
    std::cout << element << std::endl;
  return 0;
}