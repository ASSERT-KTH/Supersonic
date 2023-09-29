unsigned char R[32];
int i=0, h=0, b=0;

int main() {
    char c;
    while (read(0, &c, 1)) {
        if (i > 9) {
            printf("%d %d\n", h, b - h);
            i = h = b = 0;
            memset(R, 0, sizeof(R));
        }
        b += !!R[c];
        h += !(R[c] ^= 1 << i % 5);
        ++i;
    }
    return 0;
}