#include <stdio.h>

int main(void) {
    int h, m, s, t;
    
    // Continue reading input until EOF or h is -1
    while(scanf("%d%d%d", &h, &m, &s) != EOF && h != -1) {
        // Calculate transformed time
        t = (120 - h * 60 - m) * 60 - s;
        
        // Print transformed time
        printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);
    }

    return 0;
}