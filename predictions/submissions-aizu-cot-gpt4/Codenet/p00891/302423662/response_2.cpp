#include <bits/stdc++.h>
#define N 3
using namespace std;
typedef unsigned long long ull;
bool im[1010][1010], pa[110][110];
int w, h, p, ans;
vector<ull> used;
void ppp() {
  ull a = 0;
  ull** roll = new ull*[1001];
  for(int i = 0; i < 1001; ++i)
    roll[i] = new ull[1001]();
  
  // Rest of the code in the function...
  
  for(int i = 0; i < 1001; ++i)
    delete [] roll[i];
  delete [] roll;
}
void ch1() {
  // Code in the function...
  ppp();
}
int main() {
  // Code in the function...
  used.reserve(w*h*p);  // preallocate memory for the vector
  while (cin >> w >> h >> p, w) {
    // Code in the function...
    for (int i = 0; i < 3; i++) {
      ppp();
      ch1();
      ppp();
      ch1();
      ch();
    }
    ppp();
    ch1();
    ppp();
    cout << ans << endl;
  }
  return 0;
}