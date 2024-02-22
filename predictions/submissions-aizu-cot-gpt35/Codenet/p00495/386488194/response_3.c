#include <stdio.h>
#include <limits.h>

int main() {
    int c[5004], d[5004], num_elements, x;
    int min_steps = INT_MAX;
    
    // Read input
    scanf("%d", &num_elements);
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &c[i]);
    }
    
    // Calculate minimum steps
    while (scanf("%d", &x) != EOF) {
        int u = 0;
        int t = 0;
        
        for (int i = 0; i < num_elements; i++) {
            t = d[i];
            d[i] = (x != c[i]) ? u : t + 1;
            u = d[i] > u ? d[i] : u;
        }
        
        min_steps = (u > min_steps) ? min_steps : u;
    }
    
    // Print result
    printf("%d\n", min_steps);
    
    return 0;
}