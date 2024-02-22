#include <bits/stdc++.h>
using namespace std;
#define for_(i, a, b) for (int i = (a); i < (b); ++i)
#define for_rev(i, a, b) for (int i = (a); i >= (b); --i)
typedef vector<int> Ary;
typedef vector<Ary> Mat;
struct Edge {
  int to, c;
};
void maxUpdate(int &a, int b) { a = max(a, b); }
void mul(Mat &res, Mat &a, Mat &b) {
  int N = a.size();
  for_(i, 0, N) {
    bool skip = a[i][k] < 0;
    if (!skip) {
      for_(j, 0, N) for_(k, 0, N) {
        if (b[k][j] >= 0)
          maxUpdate(res[i][j], a[i][k] + b[k][j]);
      }
    }
  }
}
// rest of the code remains the same
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  // rest of the main function
}