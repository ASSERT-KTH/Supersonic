#include <iostream>
using namespace std;
int main() {
  int is;
  int h, m, s;
  cin >> is;
  h = is / 3600;
  m = (is % 3600) / 60;
  s = is % 60;
  cout << h << ":" << m << ":" << s << endl;
  return 0;
}