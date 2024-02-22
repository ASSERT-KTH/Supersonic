#include <iostream>
#include <bitset>
using namespace std;
int main() {
  bitset<30> data;
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data.set(n-1); // bitset is 0-indexed
  }
  for (int i = 1; i <= 30; i++) {
    if (!data.test(i-1)) // bitset is 0-indexed
      cout << i << endl;
  }
}