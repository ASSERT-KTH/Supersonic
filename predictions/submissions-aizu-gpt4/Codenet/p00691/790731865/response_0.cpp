#include <iostream>
#define N 1112
using namespace std;

int tb[N], ans[N];

inline int nr(int a, int z) {
    for (int i = z; i >= 1; --i) {
        if (tb[i] <= a) {
            return tb[i];
        }
    }
    return 0;
}

inline int calc(int z) {
    int z3 = z * z * z;
    int ret = z3;
    for (int i = 1; i < z; i++) {
        int i3 = i * i * i;
        int j3 = nr(z3 - i3, i);
        if (i3 + j3 == z3) {
            ret = 0;
            break;
        }
        ret = min(ret, z3 - i3 - j3);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i < N; i++)
        tb[i] = i * i * i;
    for (int i = 1; i < N; i++)
        ans[i] = calc(i);
    int n;
    while (cin >> n, n)
        cout << ans[n] << '\n';
    return 0;
}