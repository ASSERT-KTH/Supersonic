#include <cstdio>
#include <deque>
using namespace std;

int main() {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        deque<char> dq;
        char a, b, c;
        while ((a = getchar()) != '\n' && a != EOF) {
            b = getchar();
            c = getchar();
            if (a == '<' && b == '-')
                dq.push_front(c);
            else if (a == '-' && b == '>')
                dq.push_back(c);
            getchar();
        }
        for (char ch : dq)
            putchar(ch);
        putchar('\n');
        if (a == EOF)
            break;
    }
    return 0;
}