#include <cstdio>
#include <vector>

class Heap {
public:
  Heap() : n(0) {
    array.reserve(2000000);
  }

  void insert(int data) {
    array.push_back(data);
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
      int right = son + 1;
      if (right <= end && array[son] < array[right]) {
        son = right;
      }
      if (array[dad] > array[son]) {
        return;
      } else {
        std::swap(array[son], array[dad]);
        dad = son;
        son = dad * 2 + 1;
      }
    }
  }

  int heap_sort(int len) {
    int i;
    std::swap(array[0], array[len - 1]);
    max_heapify(0, len - 2);
    return array[len - 1];
  }

  int extract() {
    int ret = heap_sort(n);
    n--;
    return ret;
  }

private:
  std::vector<int> array;
  int n;
};

int parseInteger(const char* buf) {
  int insert_data = 0;
  for (int i = 0; buf[i] != '\0'; i++) {
    if (buf[i] >= '0' && buf[i] <= '9') {
      insert_data = 10 * insert_data + (buf[i] - '0');
    }
  }
  return insert_data;
}

int main() {
  char buf[22];
  Heap heap;
  while (true) {
    fgets(buf, 22, stdin);
    if (buf[2] == 'd') {
      break;
    }
    if (buf[0] == 'i') {
      int insert_data = parseInteger(buf);
      heap.insert(insert_data);
    } else {
      printf("%d\n", heap.extract());
    }
  }
  return 0;
}