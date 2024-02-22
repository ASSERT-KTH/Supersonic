#include <cstdio>
#include <cstdlib>

int main() {
    std::ios_base::sync_with_stdio(false);
    int x, y;
    char z;
    while (1) {
        scanf("%d %c %d", &x, &z, &y);
        if (z == '?') {
            return EXIT_SUCCESS;
        }
        switch (z) {
            case '+':
                printf("%d\n", x + y);
                break;
            case '-':
                printf("%d\n", x - y);
                break;
            case '/':
                if (y != 0) {
                    printf("%d\n", x / y);
                } else {
                    printf("Error: Division by zero\n");
                }
                break;
            case '*':
                printf("%d\n", x * y);
                break;
            default:
                printf("Error: Unknown operator\n");
        }
    }
}