#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int join[100000], num[100000];

int find(int x) {
    if (join[x] != x) {
        join[x] = find(join[x]); // path compression
    }
    return join[x];
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); // fast IO
    
    int n, m, s, t;
    
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        join[i] = i;
        num[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &t);
        s = find(s);
        t = find(t);
        if (s != t) {
            if (num[s] < num[t])
                join[s] = join[t];
            else {
                join[t] = join[s];
                if (num[s] == num[t])
                    num[s]++;
            }
        }
    }
    int q;
    string result = "";
    
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &s, &t);
        if (find(s) == find(t))
            result += "yes\n";
        else
            result += "no\n";
    }
    printf("%s", result.c_str());
    return 0;
}