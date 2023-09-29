#include <iostream>
using namespace std;
int main() {
  int is;
  int h, m;
  cin >> is;
  h = is / 3600, m = is - h * 3600;
  cout << h << ":" << m << ":" << is << endl;
  return 0;
}
