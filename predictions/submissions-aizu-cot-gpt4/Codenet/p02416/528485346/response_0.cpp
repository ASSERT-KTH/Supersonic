#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char num[1001];

    while (cin >> num && num[0] != '0') {
        int sum = 0;
        int len = strlen(num);
        for (int i = 0; i < len; i++) {
            sum += num[i] - '0';
        }
        cout << sum << "\n";
    }

    return 0;
}