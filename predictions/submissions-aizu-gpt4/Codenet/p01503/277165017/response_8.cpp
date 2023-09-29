#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    while(b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll w, d, n, m, t, u, h, tu, th, x;
void init() {
    m = t - m % t;
    u = gcd(t, w + d);
    h = gcd(t, m);
    tu = t / u;
    th = t / h;
    ll y;
    ext_gcd(m, t, x, y);
    x = ((x % th) + th) % th;
}

int solve() {
    init();
    ll res = 0, l = 0, s = 0;
    for (ll i = 0; i < t; i += h) {
        if (s < n) {
            res += max(0LL, (i - w) / u - l);
            l = i / u;
        }
        s += x;
        if (s >= th)
            s -= th;
    }
    res += max(0LL, (t - w) / u - l);
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> w >> d >> n >> m >> t;
    w++; d--;
    printf("%.20f\n", 1.0 * solve() / tu);
    return 0;
}