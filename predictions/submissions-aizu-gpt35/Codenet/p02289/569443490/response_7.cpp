#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
class Heap {
public:
  Heap() {
    array = new int[2000000];
    n = 0;
  }
  void insert(int data) {
    array[n] = data;
    int tmp = n;
    while (tmp != 0 && array[tmp] > array[(tmp - 1) / 2]) {
      std::swap(array[tmp], array[(tmp - 1) / 2]);
      tmp = (tmp - 1) / 2;
    }
    n++;
  }
  void max_heapify(int *array, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
      if (son + 1 <= end && array[son] < array[son + 1])
        son++;
      if (array[dad] > array[son])
        break;
      std::swap(array[son], array[dad]);
      dad = son;
      son = dad * 2 + 1;
    }
  }
  int extract() {
    int ret = array[0];
    array[0] = array[n - 1];
    n--;
    max_heapify(array, 0, n - 1);
    return ret;
  }

private:
  int *array;
  int n;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int insert_data;
  char buf[22];
  Heap heap;
  while (true) {
    fgets(buf, 22, stdin);
    if (buf[2] == 'd')
      break;
    if (buf[0] == 'i') {
      insert_data = 0;
      for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] >= '0' && buf[i] <= '9') {
          insert_data = 10 * insert_data + (buf[i] - '0');
        }
      }
      heap.insert(insert_data);
    } else {
      printf("%d\n", heap.extract());
    }
  }
}