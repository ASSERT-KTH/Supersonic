#include <stdio.h>

int main(void) {
    int numCount[5004], maxLength[5004], maxSequence = 0, current, i, tmp;
    
    for (scanf("%d", &numCount[0]), i = 1; i < numCount[0]; scanf("%d", &numCount[i++]));
    
    while(scanf("%d", &current) != EOF) {
        maxSequence = 0;
        for (i = 0; i < numCount[0]; tmp = maxLength[i], maxLength[i] = maxSequence < tmp ? maxSequence = tmp : tmp, maxSequence = current - numCount[i++] ? maxSequence : tmp + 1);
        printf("%d\n", maxSequence);
        maxSequence = 0;
    }
    
    return 0;
}