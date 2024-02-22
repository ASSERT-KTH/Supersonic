#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

class MaxHeap {
public:
  void insert(int data) {
    pq.push(data);
  }
  int extract() {
    int ret = pq.top();
    pq.pop();
    return ret;
  }

private:
  priority_queue<int, vector<int>, less<int>> pq;
};

int main() {
  string line;
  MaxHeap heap;

  while (getline(cin, line)) {
    stringstream ss(line);
    string command;
    ss >> command;

    if (command == "end")
      break;

    if (command == "insert") {
      int data;
      ss >> data;
      heap.insert(data);
    } else if (command == "extract") {
      cout << heap.extract() << endl;
    }
  }
}