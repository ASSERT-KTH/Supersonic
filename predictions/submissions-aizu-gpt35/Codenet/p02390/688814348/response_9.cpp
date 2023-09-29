#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int S;
    cin >> S;

    int hours = S / 3600;
    S -= hours * 3600;
    int minutes = S / 60;
    S -= minutes * 60;
    int seconds = S;

    cout << hours << ":" << minutes << ":" << seconds << endl;

    return 0;
}