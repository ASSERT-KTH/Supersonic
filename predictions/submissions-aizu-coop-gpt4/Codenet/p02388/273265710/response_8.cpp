#include <iostream>
#include <cstdio>
using namespace std;

void cubedNum() {
    int inputNum = -1;
    do {
        scanf("%d", &inputNum);
    } while (inputNum < 0 || inputNum > 100);
    
    int result = inputNum * inputNum * inputNum;
    printf("%d\n", result);
    return;
}

int main() {
    cubedNum();
    return 0;
}