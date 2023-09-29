#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char num[1001];
    while (scanf("%s", num) && num[0] != '0') {
        int sum = 0;
        for (char* c = num; *c; ++c) {
            sum += (*c - '0');
        }
        printf("%d\n", sum);
    }
    return 0;
}