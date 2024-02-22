#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
  
    int n;
    cin >> n;
  
    pair<long long, int> p[300010], b[300010];
    long long a[300010];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i].first;
        p[i] = make_pair(a[i], i);
        b[i].second = i;
    }
  
    sort(p, p + n, greater<pair<long long, int>>());
    sort(b, b + n, greater<pair<long long, int>>());
  
    int ans = 0;
    long long sum = 0;
    int id = 0, num = 0;
  
    for (int i = 0; i < n; i++) {
        sum += a[b[i].second];
        num++;
      
        while (id < n && p[id].first >= b[i].first) {
            if (!use[p[id].second]) {
                sum += p[id].first;
                num++;
            }
            id++;
        }
      
        if (sum <= num * b[i].first)
            ans = max(ans, num);
      
        sum -= a[b[i].second];
        num--;
    }
  
    cout << ans << endl;
  
    return 0;
}