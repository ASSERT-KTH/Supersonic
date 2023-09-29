#include <algorithm>
#include <iostream>
using namespace std;

constexpr int MAX_N = 1112;
int tb[MAX_N], ans[MAX_N], N;

inline int nr(int a) {
    int* ret = upper_bound(tb, tb+MAX_N, a);
    return *(ret - 1);
}

inline int calc(int z) {
    int z3 = z * z * z, ret = z3;
    for (int i = 1, i3; (i3=i*i*i) <= ret; i++) {
        int j3 = nr(z3 - i3);
        ret = min(ret, z3 - i3 - j3);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for (int i = 1; i < MAX_N; i++)
        tb[i] = i * i * i;
    for (int i = 1; i < MAX_N; i++)
        ans[i] = calc(i);
    while (cin >> N, N)
        cout << ans[N] << '\n';
}