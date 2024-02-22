#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  do {
    a = a % b;
    swap(a, b);
  } while (b != 0);
  cout << a << endl;
}