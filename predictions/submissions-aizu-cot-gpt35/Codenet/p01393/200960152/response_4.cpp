#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

const double EPS = 1e-8;

bool in_upper(const double& seta) {
    return (EPS < seta && seta < M_PI - EPS);
}

bool comp(const std::pair<double, double>& a, const std::pair<double, double>& b) {
    return std::abs(a.first - b.first) < EPS ? a.second + EPS < b.second : a.first < b.first;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<std::pair<double, double>> v;
    
    for (int i = 0; i < n; i++) {
        double x, y, r;
        std::cin >> x >> y >> r;
        std::complex<double> c(x, y);
        double d = std::abs(c), s = std::arg(c), a = std::sqrt(d * d - r * r);
        double ds = std::acos((d * d + a * a - r * r) / (2 * d * a));
        double start = s - ds, end = s + ds;
        if (start > M_PI)
            start -= 2 * M_PI;
        if (start < -M_PI)
            start += 2 * M_PI;
        if (end > M_PI)
            end -= 2 * M_PI;
        if (end < -M_PI)
            end += 2 * M_PI;
        std::pair<double, double> tmp = std::make_pair(in_upper(start) ? start : 0, in_upper(end) ? end : M_PI);
        if (tmp.first < EPS && M_PI - EPS < tmp.second)
            continue;
        v.push_back(tmp);
    }
    
    std::sort(v.begin(), v.end(), comp);
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j].first - EPS < v[i].first && v[i].second < v[j].second + EPS) {
                v.erase(v.begin() + i);
                i--;
                break;
            }
        }
    }
    
    int m = v.size();
    std::vector<std::vector<double>> dp1(m + 1, std::vector<double>(k + 1, 0));
    std::vector<std::vector<double>> dp2(m + 1, std::vector<double>(k + 1, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= k; j++) {
            dp1[i + 1][j] = std::max(dp1[i + 1][j], dp1[i][j]);
            if (j + 1 <= k) {
                double use = std::max(dp1[i][j], dp2[i][j]);
                dp1[i + 1][j + 1] = std::max(dp1[i + 1][j + 1], use + v[i].second - v[i].first);
                if (i < m - 1 && v[i].first == v[i + 1].first) {
                    dp2[i + 1][j + 1] = std::max(dp2[i + 1][j + 1], use + v[i + 1].first - v[i].first);
                }
            }
        }
    }
    
    double ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = std::max(ans, dp1[m][i]);
    }
    
    std::cout << std::fixed << std::setprecision(10) << ans / M_PI << "\n";
    
    return 0;
}