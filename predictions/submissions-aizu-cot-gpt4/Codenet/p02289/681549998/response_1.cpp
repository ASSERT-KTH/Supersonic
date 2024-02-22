#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define INFTY (1 << 30)

class Heap{
public:
    priority_queue<int> pq;

    void insert(int key){
        pq.push(key);
    }

    int extract(){
        if(pq.empty())
            return -INFTY;
        int maxv = pq.top();
        pq.pop();
        return maxv;
    }
};

int main() {
    Heap heap;
    int key;
    string com;
    while (1) {
        cin >> com;
        if (com == "end")
            break;
        if (com == "insert") {
            cin >> key;
            heap.insert(key);
        } else {
            cout << heap.extract() << "\n";
        }
    }
    return 0;
}