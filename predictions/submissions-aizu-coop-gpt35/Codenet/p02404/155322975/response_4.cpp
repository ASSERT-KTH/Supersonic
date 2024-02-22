#include <iostream>
#include <string>
using namespace std;

int main() {
  int H, W;
  
  while (true) {
    cin >> H >> W;
    
    if (H == 0 && W == 0)
      break;
    
    // Check for invalid input
    if (H <= 0 || W <= 0) {
      cout << "Invalid input" << endl;
      continue;
    }
    
    string pattern;
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
  }
  
  return 0;
}