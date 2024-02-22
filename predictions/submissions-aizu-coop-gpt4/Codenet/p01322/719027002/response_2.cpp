#include <iostream>
#include <unordered_map>
using namespace std;

int encode(string& str) {
    int code = 0;
    for (int i = 0; i < 8; i++) {
        code = code * 3 + (str[i] == '*' ? 2 : str[i] - '0');
    }
    return code;
}

int main() {
    int n, m, o[100], code;
    string b[100];
    string l;
    int ans;
    unordered_map<int, int> hash_map;
    for (;;) {
        cin >> n >> m;
        if (!n && !m)
            break;
        ans = 0;
        hash_map.clear();
        for (int i = 0; i < n; i++) {
            cin >> b[i] >> o[i];
            code = encode(b[i]);
            if (hash_map.find(code) == hash_map.end())
                hash_map[code] = o[i];
            else
                hash_map[code] += o[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> l;
            code = encode(l);
            if (hash_map.find(code) != hash_map.end())
                ans += hash_map[code];
        }
        cout << ans << endl;
    }
}