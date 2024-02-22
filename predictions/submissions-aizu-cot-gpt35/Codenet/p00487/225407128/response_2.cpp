#include <iostream>
#define fs first
#define sc second
using namespace std;
typedef long long ll;

const int MAXN = 300010;
ll a[MAXN], b[MAXN];
bool use[MAXN];

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    use[i] = false;
  }
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (!use[i]) {
      sum += a[i];
      use[i] = true;
      num++;
    }
    while (id < n) {
      if (!use[id]) {
        if (sum + a[id] > (num + 1) * b[i])
          break;
        sum += a[id];
        use[id] = true;
        num++;
      }
      id++;
    }
    if (sum <= num * b[i])
      ans = max(ans, num);
    sum -= a[i];
    num--;
  }
  cout << ans << endl;
}