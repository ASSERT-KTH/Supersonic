#include <iostream>
#include <vector>
using namespace std;

inline void iterate(int n) {
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t < min)
            min = t;
        A[t]++;
    }
}

int main() {
    int n;
    cin >> n;
    int min = 2000000;
    vector<int> A(10001, 0);

    iterate(n);
    A[min]--;

    cout << min;
    for (int i = min; i < 10001; i++) {
        for (int j = 0; j < A[i]; j++) {
            cout << ' ' << i;
        }
    }
    cout << '\n';

    return 0;
}