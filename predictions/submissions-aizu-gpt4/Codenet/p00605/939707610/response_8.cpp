#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 

  int N, K, B;
  while (cin >> N >> K, N || K) {
    vector<int> S(K);
    bool a = true;
    for (int &s : S)
      cin >> s;
    while (N--) {
      for(int &s : S) {
        cin >> B;
        s -= B;
        if(s < 0) a = false;
      }
    }
    cout << (a ? "Yes\n" : "No\n");
  }
  return 0;
}