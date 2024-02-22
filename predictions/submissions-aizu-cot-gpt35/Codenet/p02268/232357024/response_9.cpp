#include <cstdio>
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  
  unordered_set<int> S;
  for (int i = 0; i < n; ++i) {
    int num;
    scanf("%d", &num);
    S.insert(num);
  }
  
  int cnt = 0;
  int q;
  scanf("%d", &q);
  
  for (int i = 0; i < q; ++i) {
    int T;
    scanf("%d", &T);
    
    if (S.count(T) > 0) {
      ++cnt;
    }
  }
  
  cout << cnt << endl;
  return 0;
}