#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for (const auto& val : A) {
        cout << val << ' ';
    }
    
    cout << '\n';
    return 0;
}