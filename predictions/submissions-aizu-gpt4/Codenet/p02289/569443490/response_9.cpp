#include <queue>
#include <iostream>
#include <vector>

using namespace std;

priority_queue<int> heap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int insert_data;
    char command[22];
    while (true) {
        cin >> command;
        if (command[2] == 'd')
            break;
        if (command[0] == 'i') {
            cin >> insert_data;
            heap.push(insert_data);
        } else {
            cout << heap.top() << '\n';
            heap.pop();
        }
    }
}