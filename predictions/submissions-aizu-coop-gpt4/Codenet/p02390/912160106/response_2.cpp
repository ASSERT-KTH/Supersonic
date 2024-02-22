#include <iostream>
using namespace std;
int main() {
  int input_seconds;    // Renamed variable for better readability
  int h, m, s;
  cin >> input_seconds;
  
  h = input_seconds / 3600;
  m = (input_seconds % 3600) / 60;    // Used modulus operator to compute minutes directly
  s = input_seconds % 60;             // Used modulus operator to compute remaining seconds directly
  
  cout << h << ":" << m << ":" << s << endl;
  return 0;
}