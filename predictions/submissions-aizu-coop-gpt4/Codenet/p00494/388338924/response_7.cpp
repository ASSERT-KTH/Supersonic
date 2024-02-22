#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char input[1000005];
    int inputLength = 0, countJ = 0, countO = 0, countI = 0, maxCount = 0;

    scanf("%s", input);

    for(int i=0; input[i] != '\0'; i++) {
        // Resetting the counts for a new JOI substring
        if (input[i] == 'J') {
            countJ = countO = countI = 0;
        }

        // Counting the characters 'J', 'O', and 'I'
        while (input[i] == 'J') {
            countJ++;
            i++;
        }
        while (input[i] == 'O') {
            countO++;
            i++;
        }
        while (input[i] == 'I') {
            countI++;
            i++;
        }

        // Checking the condition and updating the maxCount
        if (countJ >= countO && countO <= countI) {
            maxCount = max(maxCount, countO);
        }

        // Decrement i to correct for the extra increment in the last loop
        i--;
    }

    printf("%d\n", maxCount);

    return 0;
}