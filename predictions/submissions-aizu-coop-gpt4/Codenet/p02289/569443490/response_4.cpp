#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Heap {
public:
  Heap() : vec(2000000), n(0) {}

  inline void insert(int data) {
    vec[n] = data;
    int tmp = n;
    while (tmp != 0 && vec[tmp] > vec[(tmp - 1) / 2]) {
      std::swap(vec[tmp], vec[(tmp - 1) / 2]);
      tmp = (tmp - 1) / 2;
    }
    n++;
  }

  void max_heapify(int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    if (son <= end) {
      if (vec[son] < vec[son + 1] && son + 1 <= end)
        son++;
      if (vec[dad] <= vec[son]) {
        swap(vec[son], vec[dad]);
        max_heapify(son, end);
      }
    }
  }

  inline int extract() {
    swap(vec[0], vec[n - 1]);
    max_heapify(0, n - 2);
    return vec[--n];
  }

private:
  vector<int> vec;
  int n;
};

int main() {
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