#include <iostream>
using namespace std;
int main() {
  int total_seconds;
  cin >> total_seconds;

  int hours = total_seconds / 3600;
  total_seconds %= 3600;
  
  int minutes = total_seconds / 60;
  total_seconds %= 60;

  cout << hours << ":" << minutes << ":" << total_seconds << endl;
  return 0;
}