#include <iostream>
#include <cstring>
#define M 1020001
#define L 14
char H[M][L];
int getnum(char ch) {
    switch(ch) {
        case 'A': return 1;
        case 'C': return 2;
        case 'G': return 3;
        default: return 4;
    }
}
unsigned long long getkey(char word[]) {
    unsigned long long sum = 0, p = 1;
    for (int i = 0; word[i]; i++) {
        sum += p * getnum(word[i]);
        p = p * 5;
    }
    return sum;
}
int h1(unsigned long long k) { return k % M; }
int h2(unsigned long long k) { return 1 + (k % (M - 1)); }
int insert(char str[]) {
    unsigned long long key = getkey(str);
    for (int i = 0; i < M; i++) {
        int h = (h1(key) + i * h2(key)) % M;
        if (strcmp(H[h], str) == 0) return 0;
        if (strlen(H[h]) == 0) {
            strcpy(H[h], str);
            return 1;
        }
    }
    return 0;
}
int find(char str[]) {
    unsigned long long key = getkey(str);
    for (int i = 0; i < M; i++) {
        int h = (h1(key) + i * h2(key)) % M;
        if (strcmp(H[h], str) == 0) return 1;
        if (strlen(H[h]) == 0) return 0;
    }
    return 0;
}
int main() {
    int NumOfCom;
    std::cin >> NumOfCom;
    for (int i = 0; i < M; i++) H[i][0] = '\0';
    while (NumOfCom) {
        char com[9], word[14];
        std::cin >> com >> word;
        if (com[0] == 'i') insert(word);
        else std::cout << (find(word) ? "yes\n" : "no\n");
        NumOfCom--;
    };
    return 0;
}