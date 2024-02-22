#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Heap {
public:
  void insert(int data) {
    array.push_back(data);
    push_heap(array.begin(), array.end());
  }
  int extract() {
    pop_heap(array.begin(), array.end());
    int ret = array.back();
    array.pop_back();
    return ret;
  }

private:
  vector<int> array;
};
int main() {
  int insert_data;
  string command;
  Heap heap;
  while (true) {
    cin >> command;
    if (command[0] == 'd')
      break;
    if (command[0] == 'i') {
      insert_data = stoi(command.substr(1));
      heap.insert(insert_data);
    } else {
      cout << heap.extract() << '\n';
    }
  }
}