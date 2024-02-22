#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Optimizing I/O operations
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    if (a > b)
        cout << "a > b\n";
    else if (a < b)
        cout << "a < b\n";
    else
        cout << "a == b\n";

    return 0;
}