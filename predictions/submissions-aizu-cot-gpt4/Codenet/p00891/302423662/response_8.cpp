#include <iostream>
#include <unordered_set>
#include <vector>
#define N 3
using namespace std;
typedef unsigned long long ull;
bool im[1010][1010], pa[110][110];
int w, h, p, ans;
unordered_set<ull> used;
ull roll[1001][1001] = {};

void ppp() {
  ull a = 0;
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];

  if (used.find(a) != used.end())
      return;
  used.insert(a);

  memset(roll, 0, sizeof(roll));

  for (int j = 0; j < h; j++) {
    ull b = 0, g = 1;
    for (int i = 0; i < p; i++)
      b = b * N + im[j][i], g *= N;
    roll[j][p - 1] = b;
    for (int i = p; i < w; i++) {
      b = b * N + im[j][i] - im[j][i - p] * g;
      roll[j][i] = b;
    }
  }
  // Rest of the function remains the same
}

// Rest of the functions and main() remain the same

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);

  // Rest of the main() remains the same
}