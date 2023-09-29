#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct DisjointSet
{
    std::vector<int> parent, rank, sum, min;
    std::vector<bool> visited;

    DisjointSet(int size = 0)
    {
        reset(size);
    }

    void reset(int size)
    {
        parent.resize(size);
        rank.assign(size, 0);
        sum.resize(size);
        min.resize(size);
        visited.assign(size, false);
        for (int i = 0; i < size; ++i)
        {
            parent[i] = i;
            sum[i] = min[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            if (rank[x] < rank[y])
            {
                std::swap(x, y);
            }
            parent[y] = x;
            if (rank[x] == rank[y])
            {
                ++rank[x];
            }
            sum[x] += sum[y];
            min[x] = std::min(min[x], min[y]);
        }
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        b[i] = a[i];
    }
    std::sort(b.begin(), b.end());
    std::map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[b[i]] = i;
    }
    DisjointSet ds(n);
    for (int i = 0; i < n; i++)
    {
        ds.merge(i, map[a[i]]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = ds.find(i);
        if (!ds.visited[x])
        {
            ds.visited[x] = true;
            int tmp = ds.sum[x];
            int k = std::min(ds.min[x], b[0]);
            ans += tmp + k * (ds.rank[x] - 2);
        }
    }
    std::cout << ans << "\n";
    return 0;
}