#include <iostream>
using namespace std;

// Using long long to avoid overflow for large n
long long factorial(int n, long long a = 1) {
  // Base case
  if(n == 1 || n == 0)
    return a;
  // Tail recursion
  return factorial(n - 1, n * a);
}

int main() {
  int n;
  cin >> n;
  cout << factorial(n) << endl;
  return 0;
}