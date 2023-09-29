#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    while (cin >> n >> k) {
        if (n / 2 < k) {
            cout << "-1\n";
            continue;
        }
        vector<int> p(n + 2);
        p[0] = 0;
        for (int i = 1; i < n; i += 2) {
            p[i] = i / 2 + 1;
            p[i + 1] = n - p[i];
        }
        for (int i = 0; i < k; i++) {
            if (i != 0)
                cout << "\n";
            for (int j = 0; j < n - 1; j++) {
                int a = (p[j] + i) % n + 1;
                int b = (p[j + 1] + i) % n + 1;
                cout << a << " " << b << "\n";
            }
        }
    }
    return 0;
}