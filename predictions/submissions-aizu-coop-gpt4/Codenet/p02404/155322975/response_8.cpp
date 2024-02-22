#include <cstdio>
#include <string>
using namespace std;

int main() {
  int H, W, prevH = 0, prevW = 0;
  string rectangle;
  
  while (1) {
    scanf("%d %d", &H, &W);
    if (H == 0 && W == 0)
      break;
      
    if (H != prevH || W != prevW) {  // Only generate the rectangle if dimensions have changed
      rectangle = "";  // Reset rectangle string
      for (int i = 1; i <= H; i++) {
        string line = "";
        for (int j = 1; j <= W; j++) {
          if (i == 1 || i == H || j == 1 || j == W) {
            line += "#";
          } else {
            line += ".";
          }
        }
        rectangle += line + "\n";  // Add line to rectangle string
      }
      prevH = H;  // Update previous dimensions
      prevW = W;
    }
    
    printf("%s\n", rectangle.c_str());
  }
}