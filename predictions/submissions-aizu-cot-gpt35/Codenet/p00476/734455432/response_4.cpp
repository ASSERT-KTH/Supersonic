#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int N, H;
    cin >> N >> H;
    int d[N], h[N];
    
    int INF = 1 << 28;
    int size = 1 << 20;
    int seg_v[size * 2 - 1];
    int seg_a[size * 2 - 1];
    pair<int, int> rmq[size * 2 - 1];
    
    long long int res = 0;
    for (int i = 0; i < N; i++) {
        cin >> d[i+1] >> h[i];
    }
  
    for (int i = 0; i < N; i++) {
        int k = i + size - 1;
        rmq[k] = make_pair(h[i], i);
        while (k) {
            k = (k - 1) / 2;
            rmq[k] = max(rmq[k * 2 + 1], rmq[k * 2 + 2]);
        }
    }
    
    seg_a[0] = H;
    for (int fl = 0; fl < N; fl++) {
        if (seg_a[0] - seg_v[0] > H) {
            seg_a[0] = seg_v[0] + H;
            while (fl) {
                fl = (fl - 1) / 2;
                seg_v[fl] = max(seg_v[fl * 2 + 1] + seg_a[fl * 2 + 1], seg_v[fl * 2 + 2] + seg_a[fl * 2 + 2]);
            }
        }
        seg_a[fl] -= d[fl];
        while (true) {
            int idx = rmq[0].second;
            if (h[idx] > seg_a[0] - seg_v[0]) {
                h[idx] = seg_a[0] - seg_v[0];
                int k = idx + size - 1;
                rmq[k] = make_pair(h[idx], idx);
                while (k) {
                    k = (k - 1) / 2;
                    rmq[k] = max(rmq[k * 2 + 1], rmq[k * 2 + 2]);
                }
                continue;
            }
            int s = (seg_a[0] - seg_v[0]) / h[idx];
            int hp = seg_a[fl+1];
            int need = -hp + 1;
            int t = (need / h[idx]) + !!(need % h[idx]);
            int num = min(s, t);
            seg_a[fl+1] += h[idx] * num;
            res += num;
            if (seg_a[0] - seg_v[0] > 0)
                break;
        }
    }
    
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}