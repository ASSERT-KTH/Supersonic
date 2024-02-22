#include <cstdlib>
#include <iostream>
#include <string>

int cket(const std::string &str, int i) {
    int n = 1;
    for (; i < str.size(); ++i) {
        if (str[i] == '(')
            n++;
        if (str[i] == ')')
            n--;
        if (n == 0)
            break;
    }
    return i;
}

int expand(const std::string &str, int s, int e, int &n) {
    for (int i = s; i < e; ++i) {
        if (isdigit(str[i])) {
            int num = 0;
            while (isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            int s1, e1;
            if (str[i] == '(') {
                int k = cket(str, i + 1);
                s1 = i + 1;
                e1 = k;
                i = k;
            } else {
                s1 = i;
                e1 = i + 1;
            }
            for (int l = 0; l < num; ++l) {
                char a = expand(str, s1, e1, n);
                if (a != '0')
                    return a;
            }
        } else {
            if (n == 0) {
                return str[i];
            }
            n--;
        }
    }
    return '0';
}

int main(void) {
    while (true) {
        std::string str;
        int n;
        std::cin >> str >> n;
        if (str == "0" && n == 0)
            break;
        std::cout << expand(str, 0, str.size(), n) << std::endl;
    }
    return 0;
}