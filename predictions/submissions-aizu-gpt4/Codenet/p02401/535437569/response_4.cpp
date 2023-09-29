#include <cstdio>
#include <unordered_map>
#include <functional>

using namespace std;

int main() {
    int x, y;
    char z;
    unordered_map<char, function<int(int,int)>> operations = {
        {'+', [](int x, int y){ return x + y; }},
        {'-', [](int x, int y){ return x - y; }},
        {'/', [](int x, int y){ return x / y; }},
        {'*', [](int x, int y){ return x * y; }}
    };

    while (scanf("%d %c %d", &x, &z, &y), z != '?') {
        printf("%d\n", operations[z](x, y));
    }
    return 0;
}