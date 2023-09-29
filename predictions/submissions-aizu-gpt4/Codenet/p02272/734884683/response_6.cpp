#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<uint32_t> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for(int i = 0; i < n; i++) {
        if(i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    return 0;
}