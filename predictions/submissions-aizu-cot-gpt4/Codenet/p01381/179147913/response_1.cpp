#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        if (n / 2 < k) {
            cout << "-1\n";
            continue;
        }
        stringstream ss;
        for (int i = 0; i < k; i++) {
            for (int j = 1; j < n; j += 2) {
                int a = ((j / 2 + 1 + i) % n) + 1;
                int b = ((n - (j / 2 + 1) + i) % n) + 1;
                ss << a << " " << b << "\n";
            }
            ss << "\n";
        }
        cout << ss.str();
    }
    return 0;
}