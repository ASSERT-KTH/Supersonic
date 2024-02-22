#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> data;
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data.insert(n);
  }
  for (int i = 1; i <= 30; i++) {
    if (data.find(i) == data.end())
      cout << i << endl;
  }
}