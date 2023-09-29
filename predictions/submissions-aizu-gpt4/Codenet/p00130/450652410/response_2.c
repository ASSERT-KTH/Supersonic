#include <cstdio>
#include <vector>

void optimize_train() {
    std::vector<char> train(52, '\0');
    int t = 25, s = 25;
    int c = getchar();
    train[t] = c;
    int a = getchar();
    while (a != '\n' && a != EOF) {
        int b = getchar();
        c = getchar();
        if (a == '<' && b == '-') {
            train[--t] = c;
            if (t < s)
                s = t;
        } else if (a == '-' && b == '>')
            train[++t] = c;
        a = getchar();
    }
    printf("%s\n", &train[s]);
}

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i)
        optimize_train();
    return 0;
}