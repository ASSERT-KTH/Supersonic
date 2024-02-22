#include <iostream>
#include <string>

char expand(const std::string& str, int& index, int n) {
    int i = index;
    while (i < str.size()) {
        if (std::isdigit(str[i])) {
            int j = 1;
            while (std::isdigit(str[i + j]))
                j++;
            int num = std::stoi(str.substr(i, j));
            int s, e;
            if (str[i + j] == '(') {
                int nestingLevel = 1;
                int k = i + j + 1;
                while (nestingLevel > 0) {
                    if (str[k] == '(')
                        nestingLevel++;
                    else if (str[k] == ')')
                        nestingLevel--;
                    k++;
                }
                s = i + j + 1;
                e = k - (i + j + 1) - 1;
                i = k;
            } else {
                s = i + j;
                e = 1;
                i = i + j;
            }
            for (int l = 0; l < num; ++l) {
                char a = expand(str, s, n);
                if (a != '0')
                    return a;
            }
        } else {
            if (n == 0) {
                index = i;
                return str[i];
            }
            n--;
        }
        i++;
    }
    index = i;
    return '0';
}

int main(void) {
    while (true) {
        std::string str;
        int n;
        std::cin >> str >> n;
        if (str == "0" && n == 0)
            break;
        int index = 0;
        std::cout << expand(str, index, n) << std::endl;
    }
    return 0;
}