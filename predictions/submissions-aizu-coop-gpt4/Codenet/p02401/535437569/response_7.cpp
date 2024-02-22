#include <iostream>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    char z;

    while (1) {
        cin >> x >> z >> y;
        if (z == '?') {
            return 0;
        }
        switch (z) {
            case '+':
                cout << x + y << '\n';
                break;
            case '-':
                cout << x - y << '\n';
                break;
            case '/':
                cout << x / y << '\n';
                break;
            case '*':
                cout << x * y << '\n';
                break;
        }
    }
    return 0;
}