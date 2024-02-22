#include <algorithm>
#include <iostream>
using namespace std;
int tb[1113], ans[1113], N;

int nr(int a) {
    int left = 2, right = 1111;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (tb[mid] > a)
            right = mid;
        else
            left = mid + 1;
    }
    return tb[left - 1];
}

int calc(int z) {
    int z3 = tb[z], ret = z3;
    for (int i = 1; i < z; i++) {
        int i3 = tb[i], j3 = nr(z3 - i3);
        if (i3 + j3 >= z3)
            break;
        ret = min(ret, z3 - i3 - j3);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);  // speed up cin and cout
    for (int i = 1; i <= 1112; i++)
        tb[i] = i * i * i;
    for (int i = 1; i <= 1112; i++)
        ans[i] = calc(i);
    while (cin >> N, N)
        cout << ans[N] << '\n';
}