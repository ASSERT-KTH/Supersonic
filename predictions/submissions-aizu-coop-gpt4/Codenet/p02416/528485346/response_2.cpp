#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char num[1001];
    while (1) {
        cin >> num;
        if (num[0] == '0')
            break;
        int sum = 0;
        int len = strlen(num); // compute the string length once before the loop starts
        for (int i = 0; i < len; i++) { // use the pre-computed string length
            sum += num[i] - '0';
        }
        cout << sum << endl;
    }
    return 0;
}