#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int H, W;
  do {
    scanf("%d %d", &H, &W);
    if (H == 0 && W == 0)
      break;
    
    std::string pattern;
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        if (i == 1 || i == H || j == 1 || j == W) {
          pattern += "#";
        } else {
          pattern += ".";
        }
      }
      pattern += "\n";
    }
    
    cout << pattern << endl;
  } while (true);
}