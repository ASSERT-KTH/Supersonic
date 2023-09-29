#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(10001, 0);
    int t, min = 10001;
    for (int i = 0; i < n; i++) {
        cin >> t;
        A[t]++;
        if (t < min) min = t;
    }
    cout << min;
    A[min]--;
    for (int i = min+1; i < 10001; i++) {
        for (int j = 0; j < A[i]; j++) {
            cout << ' ' << i;
        }
    }
    cout << endl;
    return 0;
}