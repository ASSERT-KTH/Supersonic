#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    unordered_map<string, int> data;

    while(cin >> n >> m && (n || m)) {
        data.clear();
        string b;
        int o;
        for (int i = 0; i < n; ++i) {
            cin >> b >> o;
            data[b] = o;
        }
        
        int ans = 0;
        string l;
        for (int i = 0; i < m; ++i) {
            cin >> l;
            for(const auto& [key, value] : data) {
                bool match = true;
                for(int k = 0; k < 8; ++k) {
                    if(key[k] != '*' && key[k] != l[k]) {
                        match = false;
                        break;
                    }
                }
                if(match) {
                    ans += value;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}