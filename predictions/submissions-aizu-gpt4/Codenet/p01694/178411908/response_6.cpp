#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    int ans = 0;
    string prev, curr;
    if(n>0){
      cin >> prev;
      --n;
    }
    while(n--){
      cin >> curr;
      if ((prev[0] != curr[0]) && (prev[1] != curr[1]))
        ++ans;
      prev = move(curr);
    }
    cout << ans << '\n';
  }
  return 0;
}