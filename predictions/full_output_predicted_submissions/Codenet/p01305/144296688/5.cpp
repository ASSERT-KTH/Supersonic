#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int l = 0; l < n; l++) {
    int num[2][9], a[2][9], geitu, jacky;
    double winrate1 = 0, winrate2 = 0;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];
    }
    for (int z = 0; z < 9; z++) {
      num[0][0] = 0;
      num[1][0] = 0;
      if (a[0][0] > a[1][z])
        num[0][0] = (a[0][0] + a[1][z]);
      else
        num[1][0] = (a[0][0] + a[1][z]);
      for (int b = 0; b < 9; b++) {
        if (b == z)
          continue;
        num[0][1] = 0;
        num[1][1] = 0;
        if (a[0][1] > a[1][b])
          num[0][1] = (a[0][1] + a[1][b]);
        else
          num[1][1] = (a[0][1] + a[1][b]);
        for (int c = 0; c <