#include <iostream>
using namespace std;
int main() {
  int is;
  int h, m;
  cin >> is;
  h = is / 3600, m = is - h * 3600, s = is / 60;
  cout << h << ":" << m << ":" << s << endl;
  return 0;
}
