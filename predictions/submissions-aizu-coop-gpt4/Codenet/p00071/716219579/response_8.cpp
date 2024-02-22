#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> P;

void solve(vector<vector<int>>& M, int y, int x) {
    stack<P> dfsStack;
    dfsStack.push({y, x});

    while (!dfsStack.empty()) {
        P top = dfsStack.top();
        dfsStack.pop();
        
        int y = top.first;
        int x = top.second;

        if (y < 0 || y >= 8 || x < 0 || x >= 8 || M[y][x] == 0)
            continue;

        M[y][x] = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                dfsStack.push({y + i, x + j});
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<vector<int>> M(8, vector<int>(8));
        for (int j = 0; j < 8; j++) {
            string s;
            cin >> s;
            for (int k = 0; k < 8; k++) { 
                M[j][k] = s[k] - '0'; 
            }
        }
        int x, y;
        cin >> x >> y;
        solve(M, y - 1, x - 1);
        cout << "Data " << i + 1 << ":" << endl;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) { 
                cout << M[j][k]; 
            }
            cout << endl;
        }
    }
    return 0;
}