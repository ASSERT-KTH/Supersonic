#include <iostream>
using namespace std;

int main(void) {
    int S;
    cin >> S;
    int hr = S / 3600;
    int min = (S % 3600) / 60;
    int sec = (S % 3600) % 60;
    cout << hr << ":" << min << ":" << sec << endl;
    return 0;
}