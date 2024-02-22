#include <iostream>
#include <bitset>
#include <stack>
using namespace std;

int n, b[2][100100], f[2][100100];
bitset<100100> v;
stack<int> st;

int dfs(int s) {
    int maxi = f[0][s], num = 1;
    st.push(s);
    v[s] = true;

    while (!st.empty()) {
        int now = st.top();
        st.pop();
        for (int i = 0; i < 2; i++) {
            if (!v[b[i][now]]) {
                if (maxi == f[i][now])
                    num++;
                else if (maxi < f[i][now]) {
                    maxi = f[i][now];
                    num = 1;
                }
                if (b[i][now] != s)
                    st.push(b[i][now]);
            }
        }
    }

    if (maxi == f[1][s])
        return num + 1;
    else if (maxi < f[1][s])
        return 1;
    else
        return num;
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
            v[i] = false;
        }
        int ans = 1, temp_ans = 1;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                temp_ans *= dfs(i);
            }
        }
        ans = temp_ans % 10007;
        cout << ans << endl;
    }
}