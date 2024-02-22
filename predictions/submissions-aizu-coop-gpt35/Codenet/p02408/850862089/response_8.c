#include <stdio.h>

int main(void) {
  int Cards[52] = {0}; // Use a 1D array instead of a 2D array
  int i, n, Num;
  char Mark;
  
  scanf("%d", &n);
  getchar(); // Read and discard the newline character
  
  for (i = 0; i < 2 * n; i++) {
    Mark = getchar(); // Read the character Mark using getchar()
    scanf("%d", &Num);
    getchar(); // Read and discard the newline character
    
    int suitOffset = 0;
    if (Mark == 'H') {
      suitOffset = 13;
    } else if (Mark == 'C') {
      suitOffset = 26;
    } else if (Mark == 'D') {
      suitOffset = 39;
    }
    
    Cards[suitOffset + Num - 1] = 1;
  }
  
  for (i = 0; i < 52; i++) {
    if (Cards[i] != 1) {
      int suit = i / 13;
      int number = i % 13 + 1;
      char suitChar;
      
      if (suit == 0) {
        suitChar = 'S';
      } else if (suit == 1) {
        suitChar = 'H';
      } else if (suit == 2) {
        suitChar = 'C';
      } else {
        suitChar = 'D';
      }
      
      printf("%c %d\n", suitChar, number);
    }
  }
  
  return 0;
}