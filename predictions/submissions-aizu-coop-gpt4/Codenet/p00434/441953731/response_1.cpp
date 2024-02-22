#include <iostream>
#include <bitset>
using namespace std;
int main() {
  bitset<31> data; // 31 bits, index 0 is not used
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data.set(n); // set the nth bit to true
  }
  for (int i = 1; i <= 30; i++) {
    if (!data.test(i)) // if the ith bit is false
      cout << i << endl;
  }
}