#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    for (int &x : A)
        cin >> x;

    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++) {
        if (i != 0)
            cout << ' ';
        cout << A[i];
    }
    cout << '\n';

    return 0;
}