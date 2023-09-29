#include <iostream>
#include <string>
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::pair<int, int>> vpii;
typedef std::pair<int, int> pii;
typedef std::pair<long long, long long> pll;
const int inf = 1000000000;
const int mod = 1000000007;
const double eps = 1e-9;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  while (std::cin >> n, n) {
    int ans = 0;
    std::string now = "", next;
    for (int i = 0; i < n; ++i) {
      std::cin >> next;
      if ((now == "lu" && next == "ru") || (now == "ru" && next == "lu") ||
          (now == "ld" && next == "rd") || (now == "rd" && next == "ld")) {
        ++ans;
      }
      now.swap(next);
    }
    std::cout << ans << '\n';
  }
  return 0;
}