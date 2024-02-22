#include <iostream>
using namespace std;

class Heap {
public:
  Heap(int capacity) {
    array = new int[capacity];
    n = 0;
  }

  void insert(int data) {
    array[n] = data;
    int tmp = n;
    int parent = (tmp - 1) / 2;
    while (tmp != 0 && array[tmp] > array[parent]) {
      std::swap(array[tmp], array[parent]);
      tmp = parent;
      parent = (tmp - 1) / 2;
    }
    n++;
  }

  void max_heapify(int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
      if (son + 1 <= end && array[son] < array[son + 1])
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
    swap(array[0], array[n - 1]);
    max_heapify(0, n - 2);
    return array[--n];
  }

private:
  int *array;
  int n;
};

int main() {
  int insert_data;
  string command;
  Heap heap(2000000);  // maximum capacity, should be dynamic based on input
  while (cin >> command) {
    if (command == "end")
      break;

    if (command == "insert") {
      cin >> insert_data;
      heap.insert(insert_data);
    } else {  // extract
      cout << heap.extract() << endl;
    }
  }
}