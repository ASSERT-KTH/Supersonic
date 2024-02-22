#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<int> lists;
    bitset<300001> checked;
    
    for (int i = 2; i <= 300000; i++) {
        if (checked[i])
            continue;
        if (i % 7 == 1 || i % 7 == 6) {
            lists.push_back(i);
            for (int k = i; k <= 300000; k += i) {
                checked[k] = true;
            }
        }
    }
    
    while (true) {
        int n;
        cin >> n;
        if (n == 1)
            break;
        
        string ans;
        for (int i = 0; i < lists.size(); i++) {
            if (n % lists[i] == 0) {
                ans += " " + to_string(lists[i]);
                while (n % lists[i] == 0) {
                    n /= lists[i];
                }
            }
        }
        
        cout << n << ":" << ans << endl;
    }
    
    return 0;
}