#include <algorithm>
#include <iostream>
using namespace std;
class Heap {
public:
  Heap() {
    n = 0;
  }
  void insert(int data) {
    array[n] = data;
    int tmp = n;
    while (tmp != 0 && array[tmp] > array[(tmp - 1) >> 1]) {
      std::swap(array[tmp], array[(tmp - 1) >> 1]);
      tmp = (tmp - 1) >> 1;
    }
    n++;
  }
  void max_heapify(int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
      if (array[son] < array[son + 1])
        son++;
      if (array[dad] > array[son])
        return;
      else {
        swap(array[son], array[dad]);
        dad = son;
        son = dad * 2 + 1;
      }
    }
  }
  int heap_sort(int len) {
    int i;
    swap(array[0], array[len - 1]);
    max_heapify(0, len - 2);
    return array[len - 1];
  }
  int extract() {
    int ret = heap_sort(n);
    n--;
    return ret;
  }

private:
  int array[2000000];
  int n;
};
int main() {
  int insert_data;
  char command;
  Heap heap;
  while (true) {
    cin >> command;
    if (command == 'd')
      break;
    if (command == 'i') {
      cin >> insert_data;
      heap.insert(insert_data);
    } else {
      cout << heap.extract() << endl;
    }
  }
}