#include<bits/stdc++.h>
using namespace std;

int main() {
  int c[5004], d[5004], t, u, i;
  cin >> t;
  for(i = 0; i < t; i++)
    cin >> c[i];
  int m = 0;
  int x;
  while(cin >> x){
    for (u = i = 0; i < t; i++) {
      int temp = d[i];
      d[i] = max(m, u);
      if(x == c[i]) 
        u = temp + 1;
      m = max(m, d[i]);
    }
  }
  cout << m << "\n";
  return 0;
}