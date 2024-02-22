#include <iostream>
#include <algorithm>
using namespace std;

class Heap {
public:
  Heap() {
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
  int extract() {
    int ret = array[0];
    swap(array[0], array[n - 1]);
    n--;
    max_heapify(0, n - 1);
    return ret;
  }

private:
  int array[2000000];
  int n;
};

int main() {
  int insert_data;
  char operation;
  Heap heap;
  while (true) {
    cin >> operation;
    if (operation == 'd')
      break;
    if (operation == 'i') {
      cin >> insert_data;
      heap.insert(insert_data);
    } else {
      cout << heap.extract() << endl;
    }
  }
}