#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& b, vector<vector<int>>& f, vector<bool>& v, int s, int start, int maxi, int num) {
    v[start] = true;
    int count = num;
    vector<int> stack;
    stack.push_back(start);
    while (!stack.empty()) {
        int now = stack.back();
        stack.pop_back();
        for (int i = 0; i < 2; i++) {
            int next = b[i][now];
            if (!v[next]) {
                v[next] = true;
                if (maxi == f[i][now])
                    count++;
                else if (maxi < f[i][now]) {
                    maxi = f[i][now];
                    count = 1;
                }
                if (next == s)
                    return count;
                stack.push_back(next);
                break;
            }
        }
    }
    if (maxi == f[1][s])
        return count + 1;
    else if (maxi < f[1][s])
        return 1;
    else
        return count;
}

int main() {
    int n;
    while (cin >> n, n) {
        vector<vector<int>> b(2, vector<int>(n));
        vector<vector<int>> f(2, vector<int>(n));
        vector<bool> v(n, false);
        for (int i = 0; i < n; i++) {
            cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                ans = (ans * dfs(b, f, v, i, b[0][i], f[0][i], 1)) % 10007;
            }
        }
        cout << ans << endl;
    }
    return 0;
}