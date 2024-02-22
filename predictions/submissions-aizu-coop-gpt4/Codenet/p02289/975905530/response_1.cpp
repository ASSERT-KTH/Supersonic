#include <cstdio>
#include <limits.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Optimized pop_and_print function
void pop_and_print(priority_queue<int> &qu) {
  if (!qu.empty()) {   // Check if the queue is not empty
    printf("%d\n", qu.top());
    qu.pop();
  }
}

int main() {
  string s;
  int inp;
  priority_queue<int> qu;
  char command[10];
  while (1) {
    scanf("%s", command);
    s = string(command);
    if (s.compare("end") == 0) { // Faster string comparison
      break;
    } else if (s.compare("insert") == 0) { // Faster string comparison
      scanf("%d", &inp);
      qu.push(inp);
    } else {
      pop_and_print(qu);
    }
  }
  return 0;
}