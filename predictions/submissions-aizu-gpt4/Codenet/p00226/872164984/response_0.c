char R[100] = {0};
int i = 0, h = 0, b = 0;
int main() {
    int c;
    while(read(0, &c, 1)){
        b += !!(R[c]);
        h += !(R[c] ^= 1 << i % 5);
        if(++i > 9) {
            printf("%d %d\n", h, b - h);
            memset(R, 0, sizeof(R));
            i = h = b = 0;
        }
    }
    return 0;
}