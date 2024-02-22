#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> heap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int key;
    char com[10];
    while (1) {
        cin >> com;
        if (com[0] == 'e' && com[1] == 'n')
            break;
        if (com[0] == 'i') {
            cin >> key;
            heap.push(key);
        } else {
            cout << heap.top() << '\n';
            heap.pop();
        }
    }
    return 0;
}