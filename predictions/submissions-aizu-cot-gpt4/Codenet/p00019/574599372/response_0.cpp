#include <iostream>
#include <vector>
using namespace std;

main() {
  long long a = 1;
  int i, n;
  cin >> n;
  
  // creating a vector to store calculated factorials
  vector<long long> factorial(n+1);
  factorial[0] = 1;
  
  for (i = 2; i <= n; i++) {
    // reusing the result of the previous factorial calculation
    factorial[i] = i * factorial[i-1];
  }
  cout << factorial[n] << endl; // printing the final factorial
}