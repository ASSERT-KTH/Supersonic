#include <iostream>
using namespace std;

int main() {
    bool data[31] = {false};
    int n;

    for (int i = 1; i <= 30; i++) {
        // If i is less than or equal to 28, read the input
        if (i <= 28) {
            cin >> n;
            data[n] = true;
        }

        // Check if all numbers less than i are in the set or not
        for (int j = 1; j < i; j++) {
            if (!data[j]) {
                cout << j << endl;
                data[j] = true;
            }
        }
    }
}