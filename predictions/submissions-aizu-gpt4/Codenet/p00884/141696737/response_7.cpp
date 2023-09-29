#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> involve;
set<int> ed;
vector<bool> used;

vector<int> dfs(int now) {
    if (used[now])
        return {};
    used[now] = true;
    vector<int> ans;
    for (auto &i : involve[now]) {
        vector<int> a = dfs(i);
        ans.insert(ans.end(), a.begin(), a.end());
    }
    ans.push_back(now);
    return ans;
}

int main() {
    while (1) {
        int num = 0;
        map<string, int> mp;
        int N;
        cin >> N;
        if (!N)
            break;
        involve.assign(100000, vector<int>());
        used.assign(100000, false);
        ed.clear();
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
                } else if (st[j] == ',' || st[j] == '.') {
                    membername.push_back(st.substr(pre + 1, j - pre - 1));
                    pre = j;
                }
            }
            if (!mp.count(groupname)) {
                mp[groupname] = num++;
            }
            for (auto &name : membername) {
                if (!(mp.count(name))) {
                    mp[name] = num++;
                }
            }
            for (auto &name : membername) {
                involve[mp[groupname]].push_back(mp[name]);
                ed.emplace(mp[name]);
            }
        }
        vector<int> allnames = dfs(0);
        sort(allnames.begin(), allnames.end());
        allnames.erase(unique(allnames.begin(), allnames.end()), allnames.end());
        cout << allnames.size() << endl;
    }
    return 0;
}