#include <iostream>
#include <vector>
using namespace std;

int main() {
    int SIZE = 51000;
    vector<bool> isPrime(SIZE, false);
    isPrime[2] = true;
    for (int i = 3; i * i < SIZE; i += 2) {
        if (!isPrime[i]) {
            for (int j = i * i; j < SIZE; j += i) {
                isPrime[j] = true;
            }
        }
    }

    int n;
    while (cin >> n && n != 0) {
        int kotae = 0;
        for (int i = 2; i <= n / 2; ++i) {
            if (isPrime[i] && isPrime[n - i]) {
                kotae++;
            }
        }
        cout << kotae << endl;
    }
    return 0;
}