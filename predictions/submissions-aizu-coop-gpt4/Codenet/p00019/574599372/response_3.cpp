#include <iostream>
using namespace std;
main() {
    long long a = 1;
    int i, n;
    cin >> n;
    for (i = n; i > 1; i -= 2) {
        if (i == 2) {
            a *= 2;
        } else {
            a *= i * (i - 1);
        }
    }
    cout << a << endl;
}