#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char num[1001];
    while (true) {
        cin >> num;
        if (num[0] == '0')
            break;
        int len = strlen(num);
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += num[i] - '0';
        }
        cout << sum << "\n";
    }
    return 0;
}