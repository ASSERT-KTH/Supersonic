#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char num[1001];
    while (true) {
        cin >> num;
        if (num[0] == '0') {
            break;
        }
        int sum = 0;
        int length = strlen(num);  // Compute the length once before the loop
        for (int i = 0; i < length; i++) {  // Use the computed length in the loop condition
            sum += num[i] - '0';
        }
        cout << sum << '\n';  // Use C++ style I/O for faster output
    }
    return 0;
}