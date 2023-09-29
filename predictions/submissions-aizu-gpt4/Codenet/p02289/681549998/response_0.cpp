#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char com[10];
  while (1) {
    cin >> com;
    if (com[0] == 'e' && com[1] == 'n')
      break;
    if (com[0] == 'i') {
      int key;
      cin >> key;
      pq.push(key);
    } else {
      cout << pq.top() << "\n";
      pq.pop();
    }
  }
  return 0;
}