#include <iostream>
using namespace std;
const int MAXN = 10001;
int A[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n;
    int min_val = MAXN;
    for (int i = 0; i < n; i++) {
        cin >> t;
        A[t]++;
        min_val = min(min_val, t);
    }
    cout << min_val;
    A[min_val]--;
    for (int i = min_val; i < MAXN; i++) {
        for (int j = 0; j < A[i]; j++) {
            cout << ' ' << i;
        }
    }
    cout << endl;
    return 0;
}