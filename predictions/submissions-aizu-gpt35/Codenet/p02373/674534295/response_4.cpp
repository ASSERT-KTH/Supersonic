#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
const int MAXLOG=20;
vector<int> g[MAXN];
int fa[MAXLOG][MAXN];
int dep[MAXN];
void dfs(int u,int f){
    dep[u]=dep[f]+1;
    fa[0][u]=f;
    for(int i=0;i<g[u].size();i++)
        if(g[u][i]!=f)
            dfs(g[u][i],u);
}
void init(int n){
    dfs(1,0);
    for(int k=1;k<MAXLOG;k++)
        for(int i=1;i<=n;i++)
            fa[k][i]=fa[k-1][fa[k-1][i]];
}
int lca(int u,int v){
    if(dep[u]<dep[v])
        swap(u,v);
    for(int k=MAXLOG-1;k>=0;k--)
        if(dep[fa[k][u]]>=dep[v])
            u=fa[k][u];
    if(u==v)
        return u;
    for(int k=MAXLOG-1;k>=0;k--)
        if(fa[k][u]!=fa[k][v]){
            u=fa[k][u];
            v=fa[k][v];
        }
    return fa[0][u];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int c;
            cin>>c;
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }
    init(n);
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
    return 0;
}