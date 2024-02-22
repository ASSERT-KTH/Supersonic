int main() {
    int R[99] = {0};
    int i = 0, h = 0, b = 0, c;
    while (read(0, &c, 1)) {
        b += !!R[c];
        if (!(R[c] = i % 5 == 0 ? 1 : 0)) {
            h++;
        }
        if (++i > 9) {
            printf("%d %d\n", h, b - h);
            for (int j = 0; j < 99; j++) {
                R[j] = 0;
            }
            i = h = b = 0;
        }
    }
    return 0;
}