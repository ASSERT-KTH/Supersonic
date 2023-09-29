#include <iostream>
using namespace std;
int main() {
  int is;
  int h, m, s;
  scanf("%d", &is); // use scanf instead of cin for faster input
  h = is / 3600;
  is = is % 3600; // use modulo instead of subtraction for faster computation
  m = is / 60;
  is = is % 60;
  cout << h << ":" << m << ":" << is << endl;
  return 0;
}