#include <iostream>
using namespace std;
int main() {
  int is;
  int h, m;
  cin >> is;
  h = is / 1000;
  m = is - h * 1000;
  cout << h << ":" << m << ":" << is << endl;
  return 0;
}
