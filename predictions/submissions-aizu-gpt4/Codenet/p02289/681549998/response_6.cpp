#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
priority_queue<int> Q;

int main() {
    int key;
    char com[10];
    while (1) {
        cin >> com;
        if (com[0] == 'e' && com[1] == 'n')
            break;
        if (com[0] == 'i') {
            cin >> key;
            Q.push(key);
        } else {
            cout << Q.top() << endl;
            Q.pop();
        }
    }
    return 0;
}