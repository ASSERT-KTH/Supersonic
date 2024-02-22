#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    string result;
    if (a > b)
        result = "a > b";
    else if (a < b)
        result = "a < b";
    else
        result = "a == b";

    cout << result << "\n";
    return 0;
}