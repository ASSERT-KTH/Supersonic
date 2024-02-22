#include <iostream>
#include <stack>
using namespace std;

const int MAX_N = 100100;
int n, b[2][MAX_N], f[2][MAX_N];
bool v[MAX_N];

int dfs(int s) {
    int maxi = f[0][s], num = 1;
    stack<int> stk;
    stk.push(s);
    v[s] = true;
    while (!stk.empty()) {
        int now = stk.top();
        stk.pop();
        for (int i = 0; i < 2; ++i) {
            if (!v[b[i][now]]) {
                v[b[i][now]] = true;
                stk.push(b[i][now]);
                if (maxi == f[i][now]) {
                    ++num;
                } else if (maxi < f[i][now]) {
                    maxi = f[i][now];
                    num = 1;
                }
            }
        }
    }
    return (maxi == f[1][s]) ? num + 1 : (maxi < f[1][s]) ? 1 : num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n, n) {
        for (int i = 0; i < n; ++i) {
            cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
            v[i] = false;
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            if (!v[i]) {
                ans = (ans * dfs(i)) & 10006;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}