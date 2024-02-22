#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool data[31] = {false}; // Initialize all elements to false
    int n;
    for (int i = 0; i < 28; i++) {
        cin >> n;
        data[n] = true; // Set the corresponding index to true
    }
    for (int i = 1; i <= 30; i++) {
        if (!data[i])
            cout << i << '\n';
    }
    return 0;
}