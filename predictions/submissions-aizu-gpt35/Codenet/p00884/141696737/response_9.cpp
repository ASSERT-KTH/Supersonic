#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

bool is_prime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

long long pow_int(long long a, long long b) {
    assert(b >= 0);
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    long long ans = 1;
    long long aa = pow_int(a, b / 2);
    ans *= aa * aa;
    if (b % 2) {
        ans *= a;
    }
    return ans;
}

struct Edge {
    int from;
    int to;
    int cost;
};

struct AA {
    int now;
    int fuel;
    int cost;
};

class Compare {
public:
    bool operator()(const AA& l, const AA& r) {
        return l.cost > r.cost;
    }
};

vector<vector<int>> involve;

vector<int> dfs(int now, vector<bool>& used) {
    if (used[now]) {
        return vector<int>();
    }
    used[now] = true;
    vector<int> ans;
    for (auto i : involve[now]) {
        if (involve[i].size()) {
            vector<int> a(dfs(i, used));
            ans.insert(ans.end(), a.begin(), a.end());
        } else {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    while (1) {
        int num = 0;
        map<string, int> mp;
        set<int> ed;
        int N;
        cin >> N;
        if (!N) {
            break;
        }
        involve.clear();
        involve.resize(100000);
        for (int i = 0; i < N; ++i) {
            string st;
            cin >> st;
            string groupname;
            vector<string> membername;
            int pre = -1;
            for (int j = 0; j < st.size(); ++j) {
                if (st[j] == ':') {
                    groupname = st.substr(0, j);
                    pre = j;
                } else if (st[j] == ',' || st[j] == '.') {
                    membername.push_back(st.substr(pre + 1, j - pre - 1));
                    pre = j;
                }
            }
            if (!mp.count(groupname)) {
                mp[groupname] = num++;
            }
            for (int i = 0; i < membername.size(); ++i) {
                if (!(mp.count(membername[i]))) {
                    mp[membername[i]] = num++;
                }
            }
            for (int i = 0; i < membername.size(); ++i) {
                involve[mp[groupname]].push_back(mp[membername[i]]);
                ed.emplace(mp[membername[i]]);
            }
        }
        vector<bool> used(100001, false);
        vector<int> allnames(dfs(0, used));
        sort(allnames.begin(), allnames.end());
        const int ans(unique(allnames.begin(), allnames.end()) - allnames.begin());
        cout << ans << endl;
    }
    return 0;
}