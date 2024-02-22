#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

bool isso(long long int a) {
    if (a == 1 || a == 0)
        return false;
    for (long long int i = 2; i * i <= a; ++i) {
        if (!(a % i)) {
            return false;
        }
    }
    return true;
}

long long int powint(long long int a, long long int b) {
    assert(b >= 0);
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    long long int ans = 1;
    long long int aa = powint(a, b / 2);
    ans *= aa * aa;
    if (b % 2)
        ans *= a;
    return ans;
}

vector<vector<int>> involve;

vector<int> dfs2(const int now, vector<bool> &used) {
    if (used[now])
        return vector<int>(0);
    used[now] = true;
    vector<int> ans;
    vector<int> a;
    for (auto i : involve[now]) {
        if (involve[i].size()) {
            a = dfs2(i, used);
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
        if (!N)
            break;
        involve.clear();
        involve.resize(100000);
        for (int i = 0; i < N; ++i) {
            string st;
            cin >> st;
            string groupname;
            vector<string> membername;
            membername.reserve(100);
            int pre;
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
                involve[mp[groupname]].emplace_back(mp[membername[i]]);
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