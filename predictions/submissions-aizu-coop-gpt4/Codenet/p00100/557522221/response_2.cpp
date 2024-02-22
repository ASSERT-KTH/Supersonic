#include <iostream>
#include <map>
#include <array>
using namespace std;

int main() {
  int n, i;
  while (cin >> n, n) {
    map<int, long long> m;
    array<int, 100> arr; // assuming n <= 100
    int size = 0;
    long long p, q;
    while (n--) {
      cin >> i >> p >> q;
      if (!m[i])
        arr[size++] = i;
      m[i] += p * q;
    }
    for (int j = 0; j < size; j++) {
      auto it = m.lower_bound(arr[j]); // get iterator directly
      if (it->second >= 1000000) {
        cout << it->first << endl;
        return 0; // early exit
      }
    }
    cout << "NA" << endl;
  }
  return 0;
}