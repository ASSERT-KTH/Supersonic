#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int X[200020], Y[200020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, d;
    cin >> N >> d;

    vi indices(N);
    for (int i = 0; i < N; ++i) {
        int x, y, b;
        cin >> x >> y >> b;
        X[i] = x, Y[i] = y;
        indices[i] = i;
    }

    // Sort indices based on value of b
    sort(indices.begin(), indices.end(), [&](int i, int j) { return X[i] < X[j]; });

    ll ans = -inf;
    for (int i = 0; i < N; i++) {
        int idx = upper_bound(indices.begin() + i, indices.end(), X[indices[i]] + d, [&](int b, int i) { return b < X[i]; }) - indices.begin();

        auto x_it_min_max = minmax_element(indices.begin() + i, indices.begin() + idx, [&](int i, int j) { return X[i] < X[j]; });
        auto y_it_min_max = minmax_element(indices.begin() + i, indices.begin() + idx, [&](int i, int j) { return Y[i] < Y[j]; });

        int min_x = X[*x_it_min_max.first], max_x = X[*x_it_min_max.second];
        int min_y = Y[*y_it_min_max.first], max_y = Y[*y_it_min_max.second];

        ans = max(ans, 1ll * (max_x - min_x) * (max_y - min_y));
    }

    cout << ans << endl;

    return 0;
}