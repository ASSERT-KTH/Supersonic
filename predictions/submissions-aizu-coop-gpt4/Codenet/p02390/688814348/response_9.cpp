#include <iostream>
using namespace std;

int main(void) {
    int S;
    cin >> S;
    
    int hours = S / 3600;
    int remaining_seconds = S % 3600;
    int minutes = remaining_seconds / 60;
    int seconds = remaining_seconds % 60;
    
    cout << hours << ":" << minutes << ":" << seconds << endl;

    return 0;
}