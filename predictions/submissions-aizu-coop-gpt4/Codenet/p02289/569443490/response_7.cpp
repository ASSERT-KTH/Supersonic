#include <algorithm>
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

  void max_heapify(int start) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son < array.size()) {
      if (son + 1 < array.size() && array[son] < array[son + 1])
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

  int extract() {
    int ret = array[0];
    array[0] = array.back();
    array.pop_back();
    max_heapify(0);
    return ret;
  }

private:
  vector<int> array;
};

int main() {
  Heap heap;
  char op;
  int num;
  while (cin >> op) {
    switch (op) {
    case 'i':
      cin >> num;
      heap.insert(num);
      break;
    case 'e':
      cout << heap.extract() << endl;
      break;
    case 'd':
      return 0;
    default:
      break;
    }
  }
  return 0;
}