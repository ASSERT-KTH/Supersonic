#include <iostream>
using namespace std;

int main(void) {
  int S;
  cin >> S;
  
  int hours = S / 3600;    // calculate hours
  int minutes = (S % 3600) / 60;    // calculate minutes
  int seconds = S - (hours * 3600 + minutes * 60);    // calculate seconds
  
  cout << hours << ":" << minutes << ":" << seconds << endl;
}