#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long i, n, s, a;
    vector<long long> j;
    while (true) {
        cin >> n;
        if (!n)
            break;
        j.resize(n);
        a = s = 0;
        for (i = 0; i < n; ++i) {
            cin >> a;
            s += a;
        }
        for (i = n - 1; i > 0; --i)
            cin >> j[i];
        for (; n > 0; --n) {
            a = max(n * s, a);
            s += j[n];
        }
        cout << a << "\n";
    }
    return 0;
}