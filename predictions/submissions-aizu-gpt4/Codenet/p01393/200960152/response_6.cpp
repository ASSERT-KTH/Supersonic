#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <iomanip>
using namespace std;

constexpr double EPS = 1e-8;
constexpr double PI = acos(-1);

struct AngleRange {
    double low, high;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<AngleRange> v;
    for (int i = 0; i < n; ++i) {
        double x, y, r;
        cin >> x >> y >> r;
        complex<double> c(x, y);
        double d = abs(c), s = arg(c), a = sqrt(d * d - r * r);
        double ds = acos((d * d + a * a - r * r) / (2 * d * a));
        double start = s - ds, end = s + ds;

        start = (start > PI) ? start - 2 * PI : (start < -PI) ? start + 2 * PI : start;
        end = (end > PI) ? end - 2 * PI : (end < -PI) ? end + 2 * PI : end;

        if ((EPS < start && start < PI - EPS) || (EPS < end && end < PI - EPS)) {
            v.push_back({(EPS < start && start < PI - EPS) ? start : 0, (EPS < end && end < PI - EPS) ? end : PI});
        }
    }

    sort(v.begin(), v.end(), [](const AngleRange& a, const AngleRange& b) {
        return a.low < b.low || (abs(a.low - b.low) < EPS && a.high < b.high);
    });

    vector<AngleRange> filtered;
    filtered.reserve(v.size());
    for (const auto &range : v) {
        while (!filtered.empty() && filtered.back().low - EPS < range.low && range.high < filtered.back().high + EPS) {
            filtered.pop_back();
        }
        filtered.push_back(range);
    }

    int m = filtered.size();

    vector<int> max_l(m), max_r(m);
    for (int i = 0; i < m; ++i) {
        max_l[i] = upper_bound(filtered.begin(), filtered.end(), AngleRange{filtered[i].high, 0}, 
            [](const AngleRange &a, const AngleRange &b) {
                return a.low < b.low || (abs(a.low - b.low) < EPS && a.high < b.high);
            }) - filtered.begin();
        max_r[i] = max_l[i] - 1;
    }

    vector<vector<double>> dp1(m + 1, vector<double>(k + 1, 0)), dp2 = dp1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
            if (j + 1 <= k) {
                double use = max(dp1[i][j], dp2[i][j]);
                dp1[max_l[i]][j + 1] = max(dp1[max_l[i]][j + 1], use + filtered[i].high - filtered[i].low);
                if (max_r[i] != i) {
                    dp2[max_r[i]][j + 1] = max(dp2[max_r[i]][j + 1], use + filtered[max_r[i]].low - filtered[i].low);
                }
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < k + 1; ++i) {
        ans = max(ans, dp1[m][i]);
    }
    cout << fixed << setprecision(10) << ans / PI << "\n";
    return 0;
}