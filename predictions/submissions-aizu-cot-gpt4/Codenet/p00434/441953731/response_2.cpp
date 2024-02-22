#include <iostream>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  set<int> data;
  data.reserve(30);  // Reserve space for 30 elements
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data.insert(n);
  }
  
  for (int i = 1; i <= 30; i++) {
    if (!data.count(i))
      cout << i << '\n';
  }

  return 0;
}