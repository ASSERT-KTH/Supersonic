#include <iostream>

using namespace std;
const int MAX = 1000001;
int S[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  
  int maxScore = 0;
  int maxPerson = 0;
  
  while (m--) {
    int a, b;
    cin >> a >> b;
    S[a] += b;
    
    if (a == maxPerson || S[a] > maxScore) {
      maxScore = S[a];
      maxPerson = a;
    }
    
    cout << maxPerson << " " << maxScore << "\n";
  }
  
  return 0;
}