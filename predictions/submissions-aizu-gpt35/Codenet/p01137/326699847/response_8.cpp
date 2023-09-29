#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int e;
    while (cin >> e, e) {
        int m = 1000000;
        int root = sqrt(e);
        for (int z = 100; z >= 0; --z) {
            int val = z * z * z;
            if (val > e)
                continue;
            int ylimit = min((int)sqrt(e - val), root);
            for (int y = ylimit; y >= 0; --y) {
                int val2 = val + y * y;
                if (val2 > e)
                    continue;
                m = min(m, (e - val2) + y + z);
                break;
            }
        }
        cout << m << '\n';
    }
    return 0;
}