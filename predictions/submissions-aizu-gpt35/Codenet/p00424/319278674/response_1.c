#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 999;

int n, t[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        memset(t, 0, sizeof(t));
        char c1, c2;
        for (int i = 0; i < n; ++i) {
            cin >> c1 >> c2;
            t[c1] = c2;
        }
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> c1;
            cout << t[c1];
        }
        cout << endl;
    }

    return 0;
}