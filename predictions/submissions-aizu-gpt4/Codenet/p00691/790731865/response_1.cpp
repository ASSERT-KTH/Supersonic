#include <algorithm>
#include <iostream>
using namespace std;

constexpr int MAX = 1112;
int tb[MAX], ans[MAX];

inline int nr(int a) {
    int* it = upper_bound(tb, tb+MAX, a);
    return *(--it);
}

inline int calc(int z) {
    int z3 = z * z * z, ret = z3;
    for (int i = 1, i3; (i3 = i * i * i) + tb[1] < z3; i++) {
        int j3 = nr(z3 - i3);
        if (i3 + j3 >= z3)
            break;
        ret = min(ret, z3 - i3 - j3);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < MAX; i++)
        tb[i] = i * i * i;
    for (int i = 1; i < MAX; i++)
        ans[i] = calc(i);

    for (int N; cin >> N, N;)
        cout << ans[N] << '\n';
}