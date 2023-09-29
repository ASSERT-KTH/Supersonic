#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int S, hours, minutes, seconds;
    cin >> S;
    hours = S / 3600;
    S %= 3600;
    minutes = S / 60;
    seconds = S % 60;
    cout << hours << ":" << minutes << ":" << seconds << "\n";
    return 0;
}