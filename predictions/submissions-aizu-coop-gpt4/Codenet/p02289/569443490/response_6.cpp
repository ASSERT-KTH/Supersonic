#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Heap {
public:
  Heap() {
    array.reserve(2000000);
  }
  void insert(int data) {
    array.push_back(data);
    int tmp = array.size() - 1;
    int parent = (tmp - 1) / 2;
    while (tmp != 0 && array[tmp] > array[parent]) {
      std::swap(array[tmp], array[parent]);
      tmp = parent;
      parent = (tmp - 1) / 2;
    }
  }
  void max_heapify(int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
      bool is_son_plus_one_in_bound = son + 1 <= end;
      if (array[son] < array[son + 1] && is_son_plus_one_in_bound)
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
    swap(array[0], array[len - 1]);
    max_heapify(0, len - 2);
    return array[len - 1];
  }
  int extract() {
    int ret = heap_sort(array.size());
    array.pop_back();
    return ret;
  }

private:
  vector<int> array;
};
int main() {
  int insert_data;
  string buf;
  Heap heap;
  while (true) {
    getline(cin, buf);
    if (buf[2] == 'd')
      break;
    if (buf[0] == 'i') {
      sscanf(buf.c_str(), "insert %d", &insert_data);
      heap.insert(insert_data);
    } else {
      cout << heap.extract() << "\n";
    }
  }
}