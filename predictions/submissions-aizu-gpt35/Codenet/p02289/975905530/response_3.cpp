#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int pop_and_print(priority_queue<int> &qu) {
  int top = qu.top(); // Store the top element
  qu.pop();
  cout << top << endl; // Print the stored top element
  return 0;
}
int main() {
  string s;
  int inp;
  priority_queue<int> qu;
  ios_base::sync_with_stdio(false); // To optimize input/output operations
  cin.tie(NULL);
  while (cin >> s) { // Use cin directly in the while loop condition
    if (s == "end") {
      break;
    } else if (s == "insert") {
      cin >> inp;
      qu.push(inp);
    } else {
      pop_and_print(qu);
    }
  }
  return 0;
}