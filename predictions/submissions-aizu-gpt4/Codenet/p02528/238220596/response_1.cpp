#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<int> a(n);
  
  for (int& num : a) 
    cin >> num;
  
  make_heap(a.begin(), a.end(), greater<int>());
  sort_heap(a.begin(), a.end(), greater<int>());
  
  for (const auto& num : a)
    cout << num << ' ';
    
  cout << '\n';
  
  return 0;
}