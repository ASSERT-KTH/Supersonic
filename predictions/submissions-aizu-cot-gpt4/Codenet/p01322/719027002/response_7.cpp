#include <iostream>
#include <unordered_map>
#include <cstdio>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, o;
    string b, l;
    unordered_map<string, int> map;
    while (scanf("%d %d", &n, &m), n || m) {
        map.clear();
        for (int i = 0; i < n; i++) {
            cin >> b >> o;
            map[b] = o;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            cin >> l;
            if(map.find(l) != map.end())
                ans += map[l];
        }
        printf("%d\n", ans);
    }
    return 0;
}