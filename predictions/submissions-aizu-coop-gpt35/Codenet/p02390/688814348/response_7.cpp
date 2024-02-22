#include <iostream>
#include <sstream>
using namespace std;

int main(void) {
    int S;
    cin >> S;

    int hours = S / 3600;
    int minutes = (S % 3600) / 60;
    int seconds = (S % 3600) % 60;

    stringstream ss;
    ss << hours << ":" << minutes << ":" << seconds;
    cout << ss.str() << endl;

    return 0;
}