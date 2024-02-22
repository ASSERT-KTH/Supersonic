#include <iostream>

int tb[1112], ans[1112];

int binarySearch(int arr[], int low, int high, int key) {
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] <= key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return arr[high];
}

int calc(int z, int tb[]) {
  int z3 = z * z * z;
  int ret = z3;
  int i = 1, j = binarySearch(tb, 1, 1111, z3 - 1);
  while (i < z && j > 0) {
    int i3 = i * i * i, j3 = tb[j];
    if (i3 + j3 >= z3)
      break;
    ret = std::min(ret, z3 - i3 - j3);
    i++;
    j = binarySearch(tb, 1, 1111, z3 - i3);
  }
  return ret;
}

int main() {
  for (int i = 1; i < 1112; i++)
    tb[i] = i * i * i;

  for (int i = 1; i < 1112; i++)
    ans[i] = calc(i, tb);

  return 0;
}