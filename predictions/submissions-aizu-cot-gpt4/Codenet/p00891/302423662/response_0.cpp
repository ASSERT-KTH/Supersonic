#include <iostream>
#include <vector>
#include <string>
#define N 3
using namespace std;
typedef unsigned long long ull;
bool im[1010][1010], pa[110][110], npa[110][110];
ull roll[1001][1001] = {};
int w, h, p, ans;
vector<ull> used;
void ppp() {
  ull a = 0;
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  int usedSize = used.size();
  for (int i = 0; i < usedSize; i++)
    if (used[i] == a)
      return;
  used.push_back(a);
  // Rest of the code...
}
void ch() {
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      npa[i][j] = pa[j][p - i - 1];
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      pa[i][j] = npa[i][j];
}
int main() {
  // ... existing code ...
  while (cin >> w >> h >> p, w) {
    string s;
    used.clear();
    for (int i = 0; i < h; i++) {
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        int t = D[s[j]];
        int a = 6;
        while (a--)
          im[i][j * 6 + a] = t & 1, t >>= 1;
      }
    }
    // ... existing code ...
  }
  return 0;
}