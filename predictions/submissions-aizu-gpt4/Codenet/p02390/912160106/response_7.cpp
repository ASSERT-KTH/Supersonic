#include <iostream>
using namespace std;
int main() {
  int is;
  cin >> is;
  int h = is / 3600;
  is %= 3600;
  int m = is / 60;
  is %= 60;
  cout << h << ":" << m << ":" << is << endl;
  return 0;
}