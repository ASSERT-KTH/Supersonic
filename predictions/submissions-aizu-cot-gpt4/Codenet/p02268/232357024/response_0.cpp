#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;
    int* S = new int[n]; // Dynamic memory allocation
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }

    int cnt = 0;
    int q, T, mid;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        cin >> T;
        int left = 0;
        int right = n;
        mid = (right + left) / 2;
        while (left < right) {
            if (T > S[mid]) {
                left = mid + 1;
            } else if (T < S[mid]) {
                right = mid;
            } else {
                ++cnt;
                break;
            }
            mid = (right + left) / 2;
        }
    }
    cout << cnt << '\n'; // Use '\n' instead of endl

    delete[] S; // Deallocate the memory
    return 0;
}