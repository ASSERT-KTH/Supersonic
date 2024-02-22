#include <iostream>
#include <string>
using namespace std;

int main() {
    string output = "";
    int results[10][10];

    // Precompute multiplication results
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            results[i][j] = i * j;
        }
    }

    // Generate output string
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            output += to_string(i) + "x" + to_string(j) + "=" + to_string(results[i][j]) + "\n";
        }
    }

    // Output the result
    cout << output;

    return 0;
}