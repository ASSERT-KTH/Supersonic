#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int n;
ll p_val[300010], b_val[300010];
int p_id[300010], b_id[300010];
bool use[300010];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a >> b_val[i];
    p_val[i] = a;
    p_id[i] = i;
    b_id[i] = i;
    use[i] = false;
  }
  sort(p_val, p_val + n);
  sort(b_val, b_val + n);
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (!use[b_id[i]]) {
      sum += p_val[b_id[i]];
      use[b_id[i]] = true;
      num++;
    }
    while (id < n && p_val[id] <= b_val[i]) {
      if (!use[p_id[id]]) {
        sum += p_val[id];
        use[p_id[id]] = true;
        num++;
      }
      id++;
    }
    while (id < n) {
      if (!use[p_id[id]]) {
        if (sum + p_val[id] > (num + 1) * b_val[i])
          break;
        sum += p_val[id];
        use[p_id[id]] = true;
        num++;
      }
      id++;
    }
    if (sum <= num * b_val[i])
      ans = max(ans, num);
    sum -= p_val[b_id[i]];
    num--;
  }
  cout << ans << endl;
}