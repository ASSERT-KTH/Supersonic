#include <iostream>
using namespace std;

int main() {
    bool data[31] = {false}; // boolean array of size 31, initialized to false
    int n;
    for (int i = 0; i < 28; i++) {
        cin >> n;
        data[n] = true; // set the value at index n to true
    }
    for (int i = 1; i <= 30; i++) {
        if (!data[i]) // check if the value at index i is false
            cout << i << endl;
    }
    return 0;
}