#include <iostream>
#include <string>
#define M 1020001
#define L 14
std::string H[M];

int getnum(char ch) {
    switch(ch) {
        case 'A': return 1;
        case 'C': return 2;
        case 'G': return 3;
        default: return 4;
    }
}

long long getkey(const char* word) {
    int sum = 0, p = 1;
    for (int i = 0; i < strlen(word); i++) {
        sum += p * getnum(word[i]);
        p *= 5;
    }
    return sum;
}

int h1(int k) { return k % M; }
int h2(int k) { return 1 + (k % (M - 1)); }

bool insert(const std::string& str) {
    int key = getkey(str.c_str());
    for (int i = 0;; i++) {
        int h = (h1(key) + i * h2(key)) % M;
        if (H[h] != str) {
            if (H[h].empty()) {
                H[h] = str;
                return true;
            }
        } else {
            return false;
        }
    }
}

bool find(const std::string& str) {
    int key = getkey(str.c_str());
    for (int i = 0;; i++) {
        int h = (h1(key) + i * h2(key)) % M;
        if (H[h] != str) {
            if (H[h].empty()) {
                return false;
            }
        } else {
            return true;
        }
    }
}

int main() {
    std::string com, word;
    int NumOfCom;
    std::cin >> NumOfCom;
    for (int i = 0; i < NumOfCom; i++) {
        std::cin >> com >> word;
        if (com[0] == 'i') {
            insert(word);
        } else {
            if (find(word)) {
                std::cout << "yes" << std::endl;
            } else {
                std::cout << "no" << std::endl;
            }
        }
    }
    return 0;
}