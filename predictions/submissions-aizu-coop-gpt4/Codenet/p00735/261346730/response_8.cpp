#include <iostream>
#include <vector>
using namespace std;

vector<int> getPrimeFactors(int n) {
    vector<int> primeFactors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primeFactors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        primeFactors.push_back(n);
    return primeFactors;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> lists;
    for (int i = 2; i <= 300000; i++) {
        if (i % 7 == 1 || i % 7 == 6) {
            lists.push_back(i);
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 1)
            break;

        vector<int> primeFactors = getPrimeFactors(n);
        vector<int> ans;

        for (int factor : primeFactors) {
            if (find(lists.begin(), lists.end(), factor) != lists.end()) {
                ans.push_back(factor);
            }
        }

        cout << n << ':';
        for (int i : ans) {
            cout << " " << i;
        }
        cout << endl;
    }
}