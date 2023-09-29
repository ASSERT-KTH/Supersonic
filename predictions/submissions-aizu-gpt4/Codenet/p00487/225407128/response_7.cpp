#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Node {
    ll a, b;
    bool operator < (const Node& rhs) const {
        return b < rhs.b;
    }
};

const int MAXN = 300010;
Node arr[MAXN];
ll prefix[MAXN];
bool selected[MAXN];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].a >> arr[i].b;
    }
    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i].a;
    }

    int ans = 0, cnt = 0;
    ll sum = 0;
    for (int i = n; i >= 1; --i) {
        if (prefix[i] <= arr[i].b) {
            ans = max(ans, i);
        } else if (sum + arr[i].a <= arr[i].b) {
            sum += arr[i].a;
            selected[i] = true;
            ++cnt;
        }
    }

    for (int i = ans + 1; i <= n; ++i) {
        if (!selected[i]) {
            if (sum + arr[i].a <= arr[ans].b) {
                sum += arr[i].a;
                ++cnt;
            }
        }
    }
    ans = max(ans, cnt);
    cout << ans << "\n";
    return 0;
}