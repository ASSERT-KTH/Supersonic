#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int min = 2000000, t;
    unordered_map<int, int> A; // Use map to save memory
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < min)
            min = t;
        A[t]++;
    }
    A[min]--;
    cout << min;
    for (int i = min; i < 10001; i++) {
        for(int j = 0; j < A[i]; j++) {
            cout << ' ' << i;
        }
    }
    cout << endl;
    return 0;
}