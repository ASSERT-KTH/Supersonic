#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)
#define dump(x) cerr << __LINE__ << ":\t" #x " = " << x << endl
using ld = long double;
using P = complex<ld>;
using G = vector<P>;
const ld pi = acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;

// rest of the code remains same

int main() {
    vector<int> ans;
    int n, m;
    cin >> n >> m;
    ld r[111], mb[111];
    vector<bool> used(n, false);

    // rest of the code remains same

    if (f) {
        rep(i, m) cout << ans[i] + 1 << "\n";
    } else {
        cout << "NG\n";
    }
}