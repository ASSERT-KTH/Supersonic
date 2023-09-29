#include<bits/stdc++.h>
using namespace std;
const int MAXN = 110000;
int n, m, q, a[2*MAXN], b[2*MAXN], c, dist[MAXN], T[MAXN], cnt, U[MAXN];
vector<int> x[MAXN], y[MAXN];
bool used[2*MAXN];

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        x[a[i]].push_back(b[i]);
        x[b[i]].push_back(a[i]);
    }
    fill(dist, dist + n + 1, 999999);
    dist[1] = 0;
    queue<int> Q;
    Q.push(1);
    while (!Q.empty())
    {
        int a1 = Q.front();
        Q.pop();
        for (int i : x[a1])
        {
            if (dist[i] > dist[a1] + 1)
            {
                dist[i] = dist[a1] + 1;
                Q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j : x[i])
        {
            if (dist[i] < dist[j])
            {
                y[i].push_back(j);
                T[j]++;
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &c);
        c--;
        queue<int> Q1;
        int ss = -1;
        if (dist[a[c]] < dist[b[c]])
            ss = b[c];
        if (dist[a[c]] > dist[b[c]])
            ss = a[c];
        if (ss >= 1 && U[ss] == 0 && used[c] == false)
        {
            Q1.push(ss);
            while (!Q1.empty())
            {
                int a1 = Q1.front();
                Q1.pop();
                if (U[a1] == 1)
                    continue;
                T[a1]--;
                used[c] = true;
                if (T[a1] != 0)
                    continue;
                cnt++;
                U[a1] = 1;
                for (int j : y[a1])
                {
                    if (U[j] == 0)
                        Q1.push(j);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}