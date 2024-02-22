#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c, t = 0;
    cin >> a >> b >> c;
    int limit = min(b, (int)sqrt(c));
    for (int s = a; s <= limit; s++) {
        if (c % s == 0) {
            t++;
            if (c / s != s && c / s <= b) {
                t++;
            }
        }
    }
    cout << t << endl;
    return 0;
}