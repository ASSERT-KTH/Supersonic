#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 1 << 28;
typedef pair<int, int> Pr;

constexpr int size = 1 << 20;

void solve() {
    int N, H;
    cin >> N >> H;
    vector<int> d(N), h(N);
    vector<int> seg_v(size * 2 - 1);
    vector<int> seg_a(size * 2 - 1);
    vector<Pr> rmq(size * 2 - 1);
    long long res = 0;
    
    for (int i = 0; i < N - 1; i++) {
        cin >> d[i+1] >> h[i];
    }

    // rest of the code remains the same.
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}