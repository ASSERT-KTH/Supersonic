#include <iostream>
#define z std::cin>>
int main(){
    int n;
    while(z n, n){
        int d[256] = {};
        for(int i=0;i<n;i++){
            char a, b;
            z a >> b;
            d[a] = b - a;
        }
        for(int i=0;i<n;i++){
            char a;
            z a;
            putchar(a + d[a]);
        }
        putchar('\n');
    }
    return 0;
}