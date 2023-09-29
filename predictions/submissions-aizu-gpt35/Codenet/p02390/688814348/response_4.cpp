#include <iostream>
using namespace std;
int main(void) {
    int S;
    cin >> S;
    int hours = S / 3600;
    S -= hours * 3600;
    int minutes = S / 60;
    S -= minutes * 60;
    cout << hours << ":" << minutes << ":" << S << endl;
    return 0;
}