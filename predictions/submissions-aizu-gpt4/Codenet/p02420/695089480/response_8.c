#include <stdio.h>
#include <string.h>

#define MAX_SIZE 201

int main() {
    char s[MAX_SIZE];
    int m, h, t, a;

    while(scanf("%200s%d", s, &m), s[0] != '-') {
        a = strlen(s);
        t = 0;
        while(m--) {
            scanf("%d", &h);
            t = (t + h) % a;
        }
        printf("%s%s\n", s + t, s);
        s[t] = '\0';
    }
    return 0;
}