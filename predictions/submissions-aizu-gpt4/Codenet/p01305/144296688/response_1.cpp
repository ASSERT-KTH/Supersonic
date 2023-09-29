#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  cin >> n;

  while(n--) {
    vector<int> a(18);
    for(int i = 0; i < 18; ++i) cin >> a[i];
    sort(a.begin(), a.end());
  
    double winrate1 = 0, winrate2 = 0, total = 0;
    do {
      int geitu = 0, jacky = 0;
      for(int i = 0; i < 9; ++i) {
        if(a[i] > a[i + 9]) geitu += a[i] + a[i + 9];
        else jacky += a[i] + a[i + 9];
      }
      if(geitu > jacky) winrate1++;
      else if(geitu < jacky) winrate2++;
      total++;
    } while(next_permutation(a.begin(), a.end()));
  
    cout << winrate1 / total << " " << winrate2 / total << "\n";
  }
  
  return 0;
}