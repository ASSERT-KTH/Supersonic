#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
    int n;
    scanf("%d\n", &n);

    std::vector<char> train(52, '\0');
    int t = 25, s = 25;

    while(n--) {
        char a = getchar();
        train[t] = a;
        char b;
        while ((b = getchar()) != '\n' && b != EOF) {
            char c = getchar();
            if (a == '<' && b == '-') {
                train[--t] = c;
                s = std::min(t, s);
            } else if (a == '-' && b == '>')
                train[++t] = c;
            a = b;
        }
        printf("%s\n", &train[s]);
        train.assign(52, '\0');
        t = s = 25;
        if (b == EOF) break;
    }
    return 0;
}