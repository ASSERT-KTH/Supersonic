#include <iostream>
using namespace std;
int main() {
  int is;
  int h, m, s;
  cin >> is;
  h = is / 3600;
  s = s - h * 3600;
  m = s / 60;
  s = s - m * 60;
  cout << h << ":" << m << ":" << s << endl;
  return 0;
}
