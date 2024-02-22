#include <iostream>
using namespace std;
const int MAX = 1000001;
int S[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  int maxNum = 0;
  int maxScore = 0;

  while (m--) {
    int a, b;
    cin >> a >> b;
    S[a] += b;
    if (S[a] > maxScore || (S[a] == maxScore && a < maxNum)) {
      maxScore = S[a];
      maxNum = a;
    }
    cout << maxNum << " " << maxScore << "\n";
  }
  return 0;
}