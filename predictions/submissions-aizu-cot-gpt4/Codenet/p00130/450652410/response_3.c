#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool ope_line() {
    char train[52];
    train[0] = '\0';
    int t = 25, s = 25;
    char line[1024];
    fgets(line, sizeof(line), stdin);
    char *ptr = line;
    char c = *ptr++;
    train[t] = c;
    char a = *ptr++;
    while (a != '\n' && a != EOF) {
        char b = *ptr++;
        c = *ptr++;
        if (a == '<' && b == '-') {
            train[--t] = c;
            if (t < s)
                s = t;
        } else if (a == '-' && b == '>') {
            train[++t] = c;
        }
        a = *ptr++;
    }
    fputs(&train[s], stdout);
    fputc('\n', stdout);
    if (a == EOF)
        return false;
    return true;
}

int main(int argc, char **argv) {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        if (!ope_line())
            break;
    }
    return 0;
}