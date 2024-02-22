#include <cstdio>
#include <string>
using namespace std;

int main() {
    // Declare the height and width variables
    int H, W;
    
    // Use a 'while' loop to continuously input pairs of integers
    while (1) {

        // Use 'scanf' for faster input
        scanf("%d %d", &H, &W);
        
        // Break the loop when both height and width are zero
        if (H == 0 && W == 0)
            break;

        // Create a string with W '#' characters
        string line(W, '#');

        // Print the line H times
        for (int i = 0; i < H; i++) {
            printf("%s\n", line.c_str());
        }

        // Print an extra newline character after each rectangle
        printf("\n");
    }

    return 0;
}