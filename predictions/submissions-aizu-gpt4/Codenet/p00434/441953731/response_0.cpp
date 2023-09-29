#include <iostream>
#include <bitset>
using namespace std;
int main() {
  bitset<30> data;
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data.set(n-1);
  }
  for (int i = 0; i < 30; i++) {
    if (!data[i])
      cout << i+1 << endl;
  }
}