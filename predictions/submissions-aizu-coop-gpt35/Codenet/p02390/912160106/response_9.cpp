#include <iostream>
using namespace std;

int main() {
  int is;

  // Read the input value from cin
  cin >> is;

  // Calculate hours, minutes, and seconds
  int h = is / 3600;  // Calculate hours
  is -= h * 3600;    // Subtract the calculated hours from the input value

  int m = is / 60;   // Calculate minutes
  is -= m * 60;      // Subtract the calculated minutes from the input value

  // Output the result
  cout << h << ":" << m << ":" << is << endl;

  return 0;
}