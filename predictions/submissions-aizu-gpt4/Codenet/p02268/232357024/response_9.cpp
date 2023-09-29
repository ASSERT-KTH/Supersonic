#include <cstdio>
#include <unordered_set>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  unordered_set<int> S;
  int temp;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    S.insert(temp);
  }
  int cnt = 0;
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int T;
    scanf("%d", &T);
    if (S.find(T) != S.end()) {
      ++cnt;
    }
  }
  printf("%d\n", cnt);
  return 0;
}