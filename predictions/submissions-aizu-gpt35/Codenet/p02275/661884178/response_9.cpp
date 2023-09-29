#include <iostream>
#include <cstring>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n;
    int min_val = 1000000;
    int A[10001] = {};
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < min_val) 
            min_val = t;
        A[t]++;
    }
    cout << min_val;
    for (int i = min_val+1; i < 10001; i++) {
        for (int j = 0; j < A[i]; j++) {
            cout << ' ' << i;
        }
    }
    cout << endl;
    return 0;
}