#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m, a;
    while (true) {
        cin >> n >> m >> a;
        if (n == 0 && m == 0 && a == 0) {
            break;
        }

        // Use map instead of 2D array
        map<pair<int, int>, int> amida;
        for (int i = 0; i < m; i++) {
            int h = 0, p = 0, q = 0;
            cin >> h >> p >> q;
            amida[{p, h}] = 1;  // Use pair as key
        }

        // Loop over the keys in the map
        for (auto it = amida.rbegin(); it != amida.rend(); ++it) {
            int p = it->first.first, h = it->first.second;
            if (p == a && it->second == 1)
                a++;
            else if (p == a - 1 && it->second == 1)
                a--;
        }

        cout << a << endl;
    }
    return 0;
}