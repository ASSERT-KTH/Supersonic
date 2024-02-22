#include <iostream>
using namespace std;

int main() {
  int S;
  cin >> S;
  
  int hours = S / 3600;
  int minutes = (S % 3600) / 60;
  int seconds = S % 60;

  cout << hours << ":" << minutes << ":" << seconds << endl;
}