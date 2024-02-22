#include <iostream>
using namespace std;

int main() {
  unsigned short H, W;
  
  while (1) {
    cin >> H >> W;
    
    if (H == 0 && W == 0)
      break;
      
    if (H == 1 || W == 1) {
      for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
          cout << "#";
        }
        cout << endl;
      }
    } else {
      for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
          if (i == 1 || i == H || j == 1 || j == W) {
            cout << "#";
          } else {
            cout << ".";
          }
        }
        cout << endl;
      }
    }
    
    cout << endl;
  }
}