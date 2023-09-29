#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    bitset<30> data;
    int n;
    for (int i = 0; i < 28; i++) {
        cin >> n;
        data.set(n - 1);
    }
    for (int i = 0; i < 30; i++) {
        if (!data.test(i))
            cout << i + 1 << endl;
    }
    return 0;
}