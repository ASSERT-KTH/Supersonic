#include <iostream>
#include <set>
using namespace std;

const int RANGE_START = 1;
const int RANGE_END = 30;

int main() {
  set<int> data;
  
  for (int i = 0; i < RANGE_START - 1; i++) {
    int n;
    cin >> n;
    data.insert(n);
  }
  
  for (int i = RANGE_START; i <= RANGE_END; i++) {
    if (data.find(i) == data.end())
      cout << i << endl;
  }
}