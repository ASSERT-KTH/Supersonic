#include <iostream>
using namespace std;
int main() {
  int is;
  int h;
  cin >> is;
  h = is / 3600.0;
  is = is - h * 3600.0;
  cout << h << ":" << is << ":" << is << endl;
  return 0;
}
