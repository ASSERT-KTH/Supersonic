#include <iostream>
using namespace std;

inline int cubed(int inputNum) {
    return inputNum * inputNum * inputNum;
}

int main() {
    int inputNum;
    do {
        cin >> inputNum;
    } while (inputNum < 0 || inputNum > 100);
    
    cout << cubed(inputNum) << endl;
    return 0;
}