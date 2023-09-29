#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll S[maxn];
int n, q;

inline int read(){
    int x=0;char ch=getchar();
    while (ch<'0'||ch>'9') { ch=getchar(); }
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x;
}

int lowbit(int x){
    return x&(-x);
}

void Update(int x,int k){
    while(x<=n){
        S[x]+=k;
        x+=lowbit(x);
    }
}

ll Query(int x){
    ll ans=0;
    while(x){
        ans+=S[x];
        x-=lowbit(x);
    }
    return ans;
}

int main() {
    n=read(); q=read();
    for (int i = 0; i < q; ++i) {
        int op=read();
        if (op) {
            int k=read();
            printf("%lld\n", Query(k));
        } else {
            int s=read(), t=read(), x=read();
            Update(s, x);
            Update(t+1, -x);
        }
    }
    return 0;
}