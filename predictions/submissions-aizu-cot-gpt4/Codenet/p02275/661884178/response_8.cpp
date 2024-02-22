#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  
  int n;
  cin >> n;
  int min = 2000000, t;
  vector<int> A(n+1, 0);
  
  for (int i = 0; i < n; i++) {
    cin >> t;
    A[t]++;
    if (t < min)
      min = t;
  }
  
  A[min]--;
  cout << min;
  for (int i = min; i <= n; i++) {
    for(int j = 0; j < A[i]; j++) { 
      cout << ' ' << i; 
    }
  }
  cout << '\n';
  
  return 0;
}