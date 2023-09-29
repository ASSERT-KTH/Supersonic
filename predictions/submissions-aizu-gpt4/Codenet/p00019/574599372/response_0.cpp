#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    unsigned long long a = 1;
    for (int i = 2; i <= n; ++i) {
        a *= i;
    }
    cout << a << endl;
    return 0;
}