#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 256

int main() {
    int n;
    scanf("%d\n", &n);

    char line[MAX_LINE_LEN];
    char train[52];
    int t = 25, s = 25;

    for (int i = 0; i < n; ++i) {
        if (!fgets(line, sizeof(line), stdin))   // read the whole line
            break;

        for (int i = 0; i < 52; ++i)            // reset the train
            train[i] = '\0';

        int len = strlen(line);
        for (int j = 0; j < len; j += 3) {      // process the characters
            char a = line[j];
            char b = line[j+1];
            char c = line[j+2];

            if (a == '<' && b == '-') {
                train[--t] = c;
                if (t < s)
                    s = t;
            } else if (a == '-' && b == '>') {
                train[++t] = c;
            }
        }

        printf("%s\n", &train[s]);              // print the train
    }

    return 0;
}