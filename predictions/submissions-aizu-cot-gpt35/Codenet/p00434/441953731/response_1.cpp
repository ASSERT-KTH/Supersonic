#include <iostream>
#include <bitset>
using namespace std;

int main() {
  bitset<30> data;
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data.set(n - 1);
  }

  string missingNumbers;
  for (int i = 0; i < 30; i++) {
    if (!data.test(i))
      missingNumbers += to_string(i + 1) + "\n";
  }

  cout << missingNumbers;

  return 0;
}