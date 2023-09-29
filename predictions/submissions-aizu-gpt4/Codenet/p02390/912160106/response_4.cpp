#include <iostream>
using namespace std;
int main() {
  int is;
  int h, m;
  cin >> is;
  h = is / 3600;
  is %= 3600;
  m = is / 60;
  is %= 60;
  cout << h << ":" << m << ":" << is << endl;
  return 0;
}