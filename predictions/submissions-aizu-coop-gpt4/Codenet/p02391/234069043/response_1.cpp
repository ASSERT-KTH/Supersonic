#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  // single cout statement for comparison
  cout << "a " << (a == b ? "==" : a > b ? ">" : "<") << " b\n";

  return 0;
}