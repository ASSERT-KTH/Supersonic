#include <stdio.h>
#include <string.h>
#define MAXN 500000
#define MAXM 10000
#define MAXQ 500000
#define MAXP 1000000000
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define gc getchar
#define pc putchar
using namespace std;

int n,m,head[MAXN],cnt,dis[MAXN],vis[MAXN];
int q[MAXQ],front,rear;

struct edge
{
    int next,to,w;
}e[MAXM<<1];

il void add(int u,int v,int w)
{
    e[++cnt].next=head[u];
    head[u]=cnt;
    e[cnt].to=v;
    e[cnt].w=w;
}

il void spfa()
{
    for(re int i=1;i<=n;++i)
        dis[i]=INF;
    dis[1]=0;vis[1]=1;
    q[rear=1]=1;
    while(front!=rear)
    {
        int u=q[front++];if(front==MAXQ)front=0;
        for(re int i=head[u],v;i;i=e[i].next)
        {
            v=e[i].to;
            if(dis[v]>dis[u]+e[i].w)
            {
                dis[v]=dis[u]+e[i].w;
                if(!vis[v])
                {
                    vis[v]=1;
                    q[++rear]=v;if(rear==MAXQ)rear=0;
                }
            }
        }
        vis[u]=0;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(re int i=1,u,v,w;i<=m;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    spfa();
    for(re int i=1;i<=n;++i)
    {
        if(dis[i]==INF)printf("-1 ");
        else printf("%d ",dis[i]);
    }
    return 0;
}