#include <queue>
#include <iostream>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, less<int>> heap;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int insert_data;
  char c;
  while (true) {
    cin >> c;
    if (c == 'd')
      break;
    if (c == 'i') {
      cin >> insert_data;
      heap.push(insert_data);
    } else {
      cout << heap.top() << "\n";
      heap.pop();
    }
  }
  return 0;
}