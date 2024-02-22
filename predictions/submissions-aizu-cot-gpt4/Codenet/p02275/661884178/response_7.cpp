#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  
    int n;
    cin >> n;

    int min = 2000000, t;
    vector<int> A(10001, 0);

    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < min)
            min = t;
        A[t]++;
    }
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