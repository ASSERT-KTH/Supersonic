#include <iostream>
using namespace std;

inline int cubedNum() {
    int inputNum;
    do {
        cin >> inputNum;
    } while (inputNum < 0 || inputNum > 100);
    return inputNum * inputNum * inputNum;
}

int main() {
    cout << cubedNum() << endl;
    return 0;
}