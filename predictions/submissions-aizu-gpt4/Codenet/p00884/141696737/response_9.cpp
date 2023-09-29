#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> involve;
vector<int> dfs2(int now, vector<bool> &used) {
    if (used[now])
        return {};
    used[now] = true;
    vector<int> ans;
    for (auto i : involve[now]) {
        auto a = dfs2(i, used);
        ans.insert(ans.end(), a.begin(), a.end());
    }
    return ans;
}

int main() {
    while (true) {
        int num = 0;
        unordered_map<string, int> mp;
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
            int pre = 0;
            for (int j = 0; j < st.size(); ++j) {
                if (st[j] == ':' || st[j] == ',' || st[j] == '.') {
                    const string name = st.substr(pre, j - pre);
                    pre = j + 1;
                    if (st[j] == ':') {
                        groupname = name;
                    } else {
                        membername.push_back(name);
                    }
                }
            }
            if (!mp.count(groupname)) {
                mp[groupname] = num++;
            }
            for (const auto &name : membername) {
                if (!mp.count(name)) {
                    mp[name] = num++;
                }
                involve[mp[groupname]].push_back(mp[name]);
            }
        }
        vector<bool> used(100001, false);
        vector<int> allnames = dfs2(0, used);
        sort(allnames.begin(), allnames.end());
        const int ans = unique(allnames.begin(), allnames.end()) - allnames.begin();
        cout << ans << endl;
    }
    return 0;
}