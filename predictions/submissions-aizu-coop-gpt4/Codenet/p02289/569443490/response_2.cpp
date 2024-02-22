#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
  void insert(int data) {
    array.push_back(data);
    int tmp = array.size() - 1;
    while (tmp != 0 && array[tmp] > array[(tmp - 1) / 2]) {
      std::swap(array[tmp], array[(tmp - 1) / 2]);
      tmp = (tmp - 1) / 2;
    }
  }
  void max_heapify(int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
      if (array[son] < array[son + 1] && son + 1 <= end)
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
    int ret = heap_sort(array.size());
    array.pop_back();
    return ret;
  }

private:
  vector<int> array;
};

int main() {
  int insert_data;
  char cmd;
  Heap heap;
  while (cin >> cmd) {
    if (cmd == 'd')
      break;
    if (cmd == 'i') {
      cin >> insert_data;
      heap.insert(insert_data);
    } else {
      cout << heap.extract() << "\n";
    }
  }
}