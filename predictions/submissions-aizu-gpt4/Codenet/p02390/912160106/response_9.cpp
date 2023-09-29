#include <iostream>
using namespace std;
int main() {
  int total_seconds;
  cin >> total_seconds;
  int h = total_seconds / 3600;
  int m = (total_seconds % 3600) / 60;
  int s = total_seconds % 60;
  cout << h << ":" << m << ":" << s << endl;
  return 0;
}