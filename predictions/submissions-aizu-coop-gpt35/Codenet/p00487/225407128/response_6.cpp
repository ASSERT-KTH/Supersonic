#include <algorithm>
#include <iostream>
#include <set>
#include <bitset>
#define fs first
#define sc second
using namespace std;
typedef long long ll;

struct Element {
  ll value;
  int index;
};

bool operator<(const Element& a, const Element& b) {
  return a.value < b.value;
}

int n;
Element p[300010], b[300010];
ll a[300010];
bitset<300010> use;

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i].value;
    p[i].value = a[i];
    p[i].index = i;
    b[i].index = i;
    use[i] = false;
  }
  sort(p, p + n);
  sort(b, b + n);
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    sum += a[b[i].index];
    use[b[i].index] = true;
    num++;
    while (id < n && p[id].value <= b[i].value) {
      sum += p[id].value;
      use[p[id].index] = true;
      num++;
      id++;
    }
    while (id < n) {
      if (sum + p[id].value > (num + 1) * b[i].value)
        break;
      sum += p[id].value;
      use[p[id].index] = true;
      num++;
      id++;
    }
    if (sum <= num * b[i].value)
      ans = max(ans, num);
    sum -= a[b[i].index];
    num--;
  }
  cout << ans << endl;
}