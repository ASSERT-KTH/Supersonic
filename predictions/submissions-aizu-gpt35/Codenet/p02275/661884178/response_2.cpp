#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int min = 2000000;
    int t, A[10001] = {0};
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < min) min = t;
        A[t]++;
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