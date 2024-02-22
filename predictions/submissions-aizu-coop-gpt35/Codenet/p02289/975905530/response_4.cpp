#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  string s;
  int inp;
  vector<int> heap;
  make_heap(heap.begin(), heap.end());
  
  while (1) {
    cin >> s;
    if (s == "end") {
      break;
    } else {
      switch (s[0]) {
        case 'i':
          cin >> inp;
          heap.push_back(inp);
          push_heap(heap.begin(), heap.end());
          break;
        case 'p':
          cout << heap.front() << endl;
          pop_heap(heap.begin(), heap.end());
          heap.pop_back();
          break;
      }
    }
  }
  
  return 0;
}