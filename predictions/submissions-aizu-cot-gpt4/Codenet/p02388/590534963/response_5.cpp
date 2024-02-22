#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int square = n * n; // Store the square of n in a variable to avoid calculating it twice
  cout << square * n << endl; // Use the stored square value
  return 0;
}