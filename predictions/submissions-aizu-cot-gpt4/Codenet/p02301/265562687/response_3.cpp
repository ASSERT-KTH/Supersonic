#include <bits/stdc++.h>
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define PI 3.141592653589793238
#define int long long
using namespace std;
//...rest of the code...

Polygon convex_hull(Polygon ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    Polygon qs(n * 2);
    for (int i = 0; i < n; i++) {
        while (k > 1) {
            double crossValue = cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]);
            if (crossValue <= 0) break;
            k--;
        }
        qs[k++] = ps[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t) {
            double crossValue = cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]);
            if (crossValue <= 0) break;
            k--;
        }
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    return qs;
}

signed main() {
    int n;
    cin >> n;
    Polygon p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    printf("%.6f\n", diameter(p));  //Reduced precision to 6 decimal places
    return 0;
}