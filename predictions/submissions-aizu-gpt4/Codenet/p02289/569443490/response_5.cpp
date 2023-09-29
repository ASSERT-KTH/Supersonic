#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

priority_queue<int, vector<int>, less<int>> heap;

int main() {
    ios::sync_with_stdio(false); // disabling synchronization of all the C++ standard stream objects with their corresponding C standard streams for faster I/O operations
    cin.tie(NULL); // unties cin from cout for faster I/O operations
    string command;
    while (getline(cin, command)) {
        if (command[2] == 'd') break;
        if (command[0] == 'i') {
            istringstream iss(command.substr(7));
            int num;
            iss >> num;
            heap.push(num);
        } else {
            cout << heap.top() << '\n';
            heap.pop();
        }
    }
    return 0;
}