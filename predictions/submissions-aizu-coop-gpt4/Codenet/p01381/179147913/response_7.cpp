#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        if (n / 2 < k) {
            cout << -1 << '\n';
            continue;
        }
        
        vector<int> p(n + 2);
        p[0] = 0;
        for (int i = 1; i < n; i += 2) {
            p[i] = i / 2 + 1;
            p[i + 1] = n - p[i];
        }
        
        vector<int> a_values(n-1), b_values(n-1);
        for (int i = 0; i < k; i++) {
            if (i != 0)
                cout << '\n';
            for (int j = 0; j < n - 1; j++) {
                a_values[j] = (p[j] + i) % n + 1;
                b_values[j] = (p[j + 1] + i) % n + 1;
            }
            for (int j = 0; j < n - 1; j++) {
                cout << a_values[j] << " " << b_values[j] << '\n';
            }
        }
    }
    return 0;
}