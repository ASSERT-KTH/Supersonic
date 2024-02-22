#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, i;
    long long p, q;

    while (cin >> n, n) {
        map<int, long long> m;
        bool s = false;

        while (n--) {
            cin >> i >> p >> q;
            m[i] += p * q;
            if (m[i] >= 1000000 && !s) {
                s = true;
                cout << i << endl;
            }
        }

        if (!s)
            cout << "NA" << endl;
    }
}