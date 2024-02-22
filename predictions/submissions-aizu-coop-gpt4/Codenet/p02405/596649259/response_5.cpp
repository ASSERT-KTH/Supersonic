#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Speed up cin and cout operations by disabling synchronization with C standard libraries
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int H, W;
    cin >> H >> W;

    // Pre-allocate a 2D vector to store the generated pattern
    vector<string> pattern(100, string(100, '.'));

    // Generate the pattern for a 100 by 100 grid
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if ((i + j) % 2 == 0) {
                pattern[i][j] = '#';
            }
        }
    }

    while (H != 0 && W != 0) {
        // Print out the pattern for the given dimensions
        for (int i = 0; i < H; i++) {
            cout << pattern[i].substr(0, W) << "\n";
        }
        cout << "\n";
        cin >> H >> W;
    }

    return 0;
}