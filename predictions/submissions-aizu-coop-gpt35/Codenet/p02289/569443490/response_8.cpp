#include <vector>
...
class Heap {
public:
  Heap() {
    n = 0;
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
  // Remove the private array member as it is now replaced by std::vector<int> array
  ...
private:
  std::vector<int> array;
  int n;
};