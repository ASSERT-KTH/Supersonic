#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {
public:
    Stack(size_t n) : s_(n), top_(0){};
    
    bool isEmpty() { return top_ == 0; }
    bool isFull() { return top_ == s_.size(); }
    
    void push(int x) {
        if (!isFull()) {
            s_[top_++] = x;
        }
    }
    
    int pop() {
        return isEmpty() ? -1 : s_[--top_];
    }

private:
    vector<int> s_;
    size_t top_;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    Stack stack(110);
    
    while (cin >> s) {
        switch(s[0]) {
            case '+':
                stack.push(stack.pop() + stack.pop());
                break;
            case '-':
                stack.push(-stack.pop() + stack.pop());
                break;
            case '*':
                stack.push(stack.pop() * stack.pop());
                break;
            default:
                stack.push(stoi(s));
                break;
        }
    }
    
    cout << stack.pop() << '\n';
    return 0;
}