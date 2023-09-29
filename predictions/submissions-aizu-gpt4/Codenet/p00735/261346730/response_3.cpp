#include <iostream>
#include <vector>
using namespace std;

vector<int> lists;
bool checked[300000 + 1] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 2; i < 300000 + 1; ++i) {
        if (checked[i]) continue;
        if (i % 7 == 1 || i % 7 == 6) {
            lists.push_back(i);
            for (int j = i; j <= 300000; j += i) {
                checked[j] = true;
            }
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 1) break;

        cout << n << ':';
        for (auto p : lists) {
            if (n % p == 0) {
                cout << " " << p;
            }
        }
        cout << endl;
    }
}