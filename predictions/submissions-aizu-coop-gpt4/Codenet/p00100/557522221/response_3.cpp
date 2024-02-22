#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n, i;
    long long p, q, s = 0;
    while(cin >> n, n) {
        unordered_map<int, long long> m;
        while(n--) {
            cin >> i >> p >> q;
            auto it = m.insert({i, 0});
            it.first->second += p * q;
        }
        for(auto it = m.begin(); it != m.end(); ++it) {
            if(it->second >= 1000000) {
                s = 1;
                cout << it->first << endl;
            }
        }
        if (!s)
            cout << "NA" << endl;
    }
}