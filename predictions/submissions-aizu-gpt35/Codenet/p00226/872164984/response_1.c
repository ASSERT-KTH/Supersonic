Here's the optimized version of the program:

char R[99];
int i = 0, h = 0, b = 0;

int main() {
    char c;
    while (read(0, &c, 1)) {
        ++i;

        if (i > 9) {
            printf("%d %d\n", h, b - h);
            fflush(stdout);
            i = h = b = 0;
            memset(R, 0, 99);
        }

        b += !!R[c];
        h += !(R[c] ^= 1 << i % 5);
    }

    return 0;
}