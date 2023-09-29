#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;

const int N = 6000;
const int M = 1 << 12;

ll gha[N];
bool vis[M][100];
ll po[1000];
int n, m;
ll ha[12];
int len[12];

void solve() {
    string text;
    for(int i = 0; i < n; i++) {
        string a;
        cin >> a;
        ll h = 0;
        len[i] = a.size();
        for(char c : a)
            h = h * 31 + c;
        ha[i] = h;
    }
    
    po[0] = 1;
    for(int i = 0; i < 999; i++) 
        po[i + 1] = po[i] * 31;
    
    int ans = 0;
    
    for(int jjj = 0; jjj < m; jjj++) {
        string a;
        cin >> a;
        text += a;
    }
    
    for(int i = 0; i < text.size(); i++) 
        gha[i + 1] = gha[i] * 31 + text[i];
    
    for(int i = 0; i < 250; i++) 
        for(int j = 0; j < (1 << n); j++) 
            vis[j][i] = 0;
    
    for(int i = 0; i < 250; i++) 
        vis[0][i] = 1;
    
    for(int j = 0; j <= text.size(); j++){
        int cur = j % 250;
        for(int i = 0; i < (1 << n); i++){
            if(!vis[i][cur])
                continue;
            for(int k = 0; k < n; k++)
                if(!(i & (1 << k)) && len[k] + j <= text.size() && ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
                    vis[i | (1 << k)][(j + len[k]) % 250] = 1;
        }
        ans += vis[(1 << n) - 1][cur];
        for(int i = 0; i < (1 << n); i++)
            vis[i][cur] = 0;
        
        vis[0][cur] = 1;
    }
    cout << ans << endl;
}

int main() {
    while (cin >> n >> m, n)
        solve();
    return 0;
}