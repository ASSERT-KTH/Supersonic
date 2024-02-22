#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> count;
    int min_value = 2000000, t;

    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < min_value)
            min_value = t;
        count[t]++;
    }
    count[min_value]--;

    cout << min_value;
    for (const auto& pair : count) {
        for (int i = 0; i < pair.second; i++) {
            cout << ' ' << pair.first;
        }
    }
    cout << endl;

    return 0;
}