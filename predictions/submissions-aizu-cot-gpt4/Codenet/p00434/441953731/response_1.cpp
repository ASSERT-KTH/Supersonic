#include <iostream>
using namespace std;

int main() {
    bool data[31] = {false}; // Initialize all elements to false
    int n;

    for (int i = 0; i < 28; i++) {
        cin >> n;
        data[n] = true; // Mark number as present
    }

    for (int i = 1; i <= 30; i++) {
        if (!data[i]) // If number is not present
            cout << i << endl;
    }

    return 0;
}