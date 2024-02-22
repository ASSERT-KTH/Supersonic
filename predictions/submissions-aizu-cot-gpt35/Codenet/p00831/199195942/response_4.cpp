#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int damerau_levenshtein_distance(const std::string& a, const std::string& b, const int alphabet_size) {
    std::unordered_map<int, int> da;
    std::vector<int> d(b.size() + 1);
    int maxdist = a.size() + b.size();
    d[0] = maxdist;
    for (int i = 0; i <= a.size(); ++i) {
        int db = 0;
        for (int j = 0; j <= b.size(); ++j) {
            int k = da[b[j - 1]], l = db, cost;
            if (i > 0 && j > 0 && a[i - 1] == b[j - 1]) {
                cost = 0;
                db = j;
            } else {
                cost = 1;
            }
            d[j] = std::min({ d[j] + cost, d[j - 1] + 1, d[j + 1] + 1, d[l] + (i - k) + (j - l) });
        }
        da[a[i - 1]] = i;
    }
    return d[b.size()];
}

void solve(int n) {
    int d;
    std::vector<std::string> name(n);
    std::cin >> d;
    for (int i = 0; i < n; ++i) {
        std::cin >> name[i];
    }
    std::sort(name.begin(), name.end());
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (damerau_levenshtein_distance(name[i], name[j], 26) > d) {
                continue;
            }
            ++count;
            std::cout << name[i] << "," << name[j] << "\n";
        }
    }
    std::cout << count << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.precision(10);
    for (;;) {
        int n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        solve(n);
    }
    return 0;
}