#include <iostream>
using namespace std;
int main() {
  int is;
  cin >> is;
  int h = is / 3600;
  int m = (is % 3600) / 60;
  int s = is % 60;
  cout << h << ":" << m << ":" << s << endl;
  return 0;
}