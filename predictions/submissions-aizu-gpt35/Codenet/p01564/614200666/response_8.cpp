#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,q;
int w[N];
int fa[N],ch[N][2],sz[N];
int v[N],sm[N],lz[N];
int lsm[N],rsm[N],ma[N],mv[N];
bool rev[N];
int stk[N],top;
inline bool nroot(int x){
    return ch[fa[x]][0]==x||ch[fa[x]][1]==x;
}
inline void pushup(int x){
    sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
    sm[x]=v[x]+sm[ch[x][0]]+sm[ch[x][1]];
    lsm[x]=max(lsm[ch[x][0]],sm[ch[x][0]]+v[x]+lsm[ch[x][1]]);
    rsm[x]=max(rsm[ch[x][1]],sm[ch[x][1]]+v[x]+rsm[ch[x][0]]);
    ma[x]=max(lsm[x],max(rsm[x],max(ma[ch[x][0]],max(ma[ch[x][1]],rsm[ch[x][0]]+v[x]+lsm[ch[x][1]]))));
    mv[x]=max(v[x],max(mv[ch[x][0]],mv[ch[x][1]]));
}
inline void revit(int x){
    swap(ch[x][0],ch[x][1]);
    swap(lsm[x],rsm[x]);
    rev[x]^=1;
}
inline void lzit(int x,int c){
    v[x]=c;
    sm[x]=sz[x]*c;
    lsm[x]=rsm[x]=ma[x]=max(0,sm[x]);
    mv[x]=c;
    lz[x]=c;
}
inline void pushdown(int x){
    if(rev[x]){
        if(ch[x][0]) revit(ch[x][0]);
        if(ch[x][1]) revit(ch[x][1]);
        rev[x]=0;
    }
    if(lz[x]!=-1){
        if(ch[x][0]) lzit(ch[x][0],lz[x]);
        if(ch[x][1]) lzit(ch[x][1],lz[x]);
        lz[x]=-1;
    }
}
inline void rotate(int x){
    int y=fa[x],z=fa[y],k=ch[y][1]==x,w=ch[x][!k];
    if(nroot(y)) ch[z][ch[z][1]==y]=x;
    ch[x][!k]=y; ch[y][k]=w;
    if(w) fa[w]=y;
    fa[y]=x; fa[x]=z;
    pushup(y); pushup(x);
}
inline void splay(int x){
    int y=x,z=0;
    stk[++z]=y;
    while(nroot(y)) stk[++z]=y=fa[y];
    while(z) pushdown(stk[z--]);
    while(nroot(x)){
        int y=fa[x],z=fa[y];
        if(nroot(y))
            rotate((ch[z][1]==y)^(ch[y][1]==x)?x:y);
        rotate(x);
    }
}
inline void access(int x){
    for(int y=0;x;y=x,x=fa[x]){
        splay(x);
        ch[x][1]=y;
        pushup(x);
    }
}
inline void makeroot(int x){
    access(x);
    splay(x);
    revit(x);
}
inline void split(int x,int y){
    makeroot(x);
    access(y);
    splay(y);
}
inline void link(int x,int y){
    makeroot(x);
    fa[x]=y;
}
inline void cut(int x,int y){
    makeroot(x);
    if(find(stk+1,stk+top+1,y)!=stk+top+1) return;
    access(y); splay(x);
    if(ch[x][0]==y&&sz[y]==1){
        ch[x][0]=fa[y]=0;
        pushup(x);
    }
}
inline int query(int x,int y){
    split(x,y);
    return ma[y];
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        v[i]=mv[i]=w[i];
        sz[i]=1;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        link(u,v);
    }
    memset(lz,-1,sizeof(lz));
    while(q--){
        int op,x,y,z;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            scanf("%d",&z);
            cut(x,y);
            link(x,n+1); link(n+1,y);
            lzit(n+1,z);
        }
        else printf("%d\n",query(x,y));
    }
    return 0;
}