#include <iostream>
#include <string>

int cket(const std::string &str, int i) {
    int n = 1;
    int size = str.size();
    while (i < size) {
        if (str[i] == '(') ++n;
        if (str[i] == ')') --n;
        if (n == 0) break;
        ++i;
    }
    return i;
}

int n;

char expand(const std::string &str, int s, int e) {
    int size = e;
    for (int i = s; i < size; ++i) {
        if (isdigit(str[i])) {
            int j = 1;
            while (isdigit(str[i + j])) ++j;
            int num = 0;
            for (int k = 0; k < j; ++k) {
                num = num * 10 + (str[i + k] - '0');
            }
            if (str[i + j] == '(') {
                int k = cket(str, i + j + 1);
                i = expand(str, i + j + 1, k);
            } else {
                i += j;
                for (int l = 0; l < num; ++l) {
                    if (n == 0) {
                        return str[i];
                    }
                    --n;
                }
            }
        } else {
            if (n == 0) {
                return str[i];
            }
            --n;
        }
    }
    return '0';
}

int main() {
    while (true) {
        std::string str;
        int size;
        std::cin >> str >> n;
        if (str == "0" && n == 0)
            break;
        size = str.size();
        std::cout << expand(str, 0, size) << '\n';
    }
    return 0;
}