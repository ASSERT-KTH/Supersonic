#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
typedef pair<int, int> pii;
int n, m;
vector<int> edge[5000];
int cnt[5000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].emplace_back(b);
        cnt[b]++;
    }
    vector<int> ans;
    ans.reserve(n);
    bool flag = false;
    vector<int> next;
    next.reserve(n);
    REP(i, n) if (cnt[i] == 0) next.emplace_back(i);
    REP(i, n) {
        int tar = next.back();
        ans.emplace_back(tar + 1);
        next.pop_back();
        if (!next.empty())
            flag = true;
        for(int to : edge[tar]) {
            if (--cnt[to] == 0)
                next.emplace_back(to);
        }
    }
    for(int i : ans) cout << i << '\n';
    cout << (flag ? "1\n" : "0\n");
    return 0;
}