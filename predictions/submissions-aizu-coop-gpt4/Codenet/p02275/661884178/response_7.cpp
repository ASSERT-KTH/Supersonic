#include <iostream>
#include <map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  
  int n;
  cin >> n;

  map<int, int> freq;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    freq[t]++;
  }

  for (auto &p: freq) {
    for (int i = 0; i < p.second; i++) {
      cout << p.first << ' ';
    }
  }
  
  cout << endl;
  return 0;
}