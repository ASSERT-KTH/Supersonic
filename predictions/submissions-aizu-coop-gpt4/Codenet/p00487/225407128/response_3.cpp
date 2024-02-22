#include <algorithm>
#include <iostream>
#include <vector>
#define fs first
#define sc second
using namespace std;
typedef long long ll;
int n;
struct Data {
  ll a;
  pair<ll, int> b;
  bool used;
};
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n;
  vector<Data> data(n);
  for (int i = 0; i < n; i++) {
    cin >> data[i].a >> data[i].b.fs;
    data[i].b.sc = i;
    data[i].used = false;
  }
  sort(data.begin(), data.end(), [](const Data& x, const Data& y) { return x.a < y.a || (x.a == y.a && x.b.fs < y.b.fs); });
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (!data[i].used) {
      sum += data[i].a;
      data[i].used = true;
      num++;
    }
    while (id < n && data[id].a <= data[i].b.fs) {
      if (!data[id].used) {
        sum += data[id].a;
        data[id].used = true;
        num++;
      }
      id++;
    }
    while (id < n) {
      if (!data[id].used) {
        if (sum + data[id].a > (num + 1) * data[i].b.fs)
          break;
        sum += data[id].a;
        data[id].used = true;
        num++;
      }
      id++;
    }
    if (sum <= num * data[i].b.fs)
      ans = max(ans, num);
    sum -= data[i].a;
    num--;
  }
  cout << ans << endl;
}