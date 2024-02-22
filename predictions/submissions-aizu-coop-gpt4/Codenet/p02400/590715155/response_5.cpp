#include <iostream>
using namespace std;

int main() {
  const double PI = 3.141592653589;
  double r;
  cin >> r;
  
  double circumference = 2 * PI * r;  // calculate circumference first
  double area = circumference * r / 2; // reuse 2*PI from circumference calculation
  
  cout << area << " " << circumference << "\n";
  
  return 0;
}