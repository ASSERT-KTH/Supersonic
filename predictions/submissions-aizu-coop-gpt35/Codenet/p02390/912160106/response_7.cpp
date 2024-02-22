#include <iostream>
using namespace std;

int main() {
  int is;
  int h, m, s;
  cin >> is;

  h = is / 3600;
  is %= 3600; // Equivalent to is = is - h * 3600

  m = is / 60;
  is %= 60; // Equivalent to is = is - m * 60

  cout << h << ":" << m << ":" << is << endl;
  return 0;
}