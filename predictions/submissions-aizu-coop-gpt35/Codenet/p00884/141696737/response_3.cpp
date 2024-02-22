#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <cmath>
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
#include <unordered_map>
#include <vector>
using namespace std;

vector<bool> primeSieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

struct edge {
    int from;
    int to;
    int cost;
};

struct aa {
    int now;
    int fuel;
    int cost;
};

class Compare {
public:
    bool operator()(const aa& l, const aa& r) { return l.cost > r.cost; }
};

vector<vector<int>> involve;
vector<int> dfs2(const int now, vector<bool>& used) {
    if (used[now])
        return vector<int>(0);
    else {
        used[now] = true;
    }
    vector<int> ans;
    for (auto i : involve[now]) {
        if (involve[i].size()) {
            vector<int> a(dfs2(i, used));
            ans.insert(ans.end(), a.begin(), a.end());
        }
        else {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    while (1) {
        int num = 0;
        unordered_map<string, int> mp;
        set<int> ed;
        int N;
        cin >> N;
        if (!N)
            break;
        involve.clear();
        involve.resize(100000);
        for (int i = 0; i < N; ++i) {
            string st;
            cin >> st;
            string groupname;
            vector<string> membername;
            int pre;
            for (int j = 0; j < st.size(); ++j) {
                if (st[j] == ':') {
                    groupname = st.substr(0, j);
                    pre = j;
                }
                else if (st[j] == ',' || st[j] == '.') {
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
        vector<int> allnames(dfs2(0, used));
        sort(allnames.begin(), allnames.end());
        const int ans(unique(allnames.begin(), allnames.end()) - allnames.begin());
        cout << ans << endl;
    }
    return 0;
}