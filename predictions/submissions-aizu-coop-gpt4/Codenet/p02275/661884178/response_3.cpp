#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false); // to speed up cin and cout
  cin.tie(nullptr); // untie cin and cout, to speed up input and output

  int n;
  cin >> n;

  const int MAX_NUM = 10001;
  int min = MAX_NUM, t, A[MAX_NUM]{};
  
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t < min)
      min = t;
    A[t]++;
  }
  A[min]--;
  
  cout << min;
  
  for (int i = min; i < MAX_NUM; i++) {
    for(int j = 0; j < A[i]; j++) {
      cout << ' ' << i;
    }
  }
  cout << endl;
  
  return 0;
}