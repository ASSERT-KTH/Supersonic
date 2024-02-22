#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int damerau_levenshtein_distance(const string& a, const string& b, const int alphabet_size) {
    vector<int> da(alphabet_size, 0);
    vector<vector<int>> d(a.size() + 1, vector<int>(b.size() + 1));
    int maxdist = a.size() + b.size();
    d[-1][-1] = maxdist;
    for (int i = 0; i <= a.size(); ++i) {
        d[i][-1] = maxdist;
        d[i][0] = i;
    }
    for (int i = 0; i <= b.size(); ++i) {
        d[-1][i] = maxdist;
        d[0][i] = i;
    }
    for (int i = 1; i <= a.size(); ++i) {
        int db = 0;
        for (int j = 1; j <= b.size(); ++j) {
            int k = da[b[j - 1]], l = db, cost;
            if (a[i - 1] == b[j - 1]) {
                cost = 0;
                db = j;
            } else {
                cost = 1;
            }
            d[i][j] = min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                           d[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1)});
        }
        da[a[i - 1]] = i;
    }
    return d[a.size()][b.size()];
}

void solve(int n) {
    int d;
    vector<string> name(n);
    scanf("%d", &d);
    for (int i = 0; i < n; i++) {
        char buffer[101];
        scanf("%s", buffer);
        name[i] = buffer;
    }
    unordered_set<string> names(name.begin(), name.end());
    int count = 0;
    for (auto it1 = names.begin(); it1 != names.end(); ++it1) {
        for (auto it2 = next(it1); it2 != names.end(); ++it2) {
            if (damerau_levenshtein_distance(*it1, *it2, 26) <= d) {
                count++;
                printf("%s,%s\n", it1->c_str(), it2->c_str());
            }
        }
    }
    printf("%d\n", count);
}

int main() {
    for (;;) {
        int n;
        scanf("%d", &n);
        if (!n) {
            break;
        }
        solve(n);
    }
    return 0;
}