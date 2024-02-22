// Combine dfs_sz and dfs into one function
void dfs(int p, int b) {
    sz[p] = 1;
    int ma = -1, md = -1;
    for (int d : g[p]) {
        if (d == b)
            continue;
        dfs(d, p);
        sz[p] += sz[d];
        if (ma < sz[d]) {
            ma = sz[d];
            md = d;
        }
    }
    if (md == -1) {
        buf[nc] = 1;
        bufdata[nc] = data[p];
        bufsm[nc + 1] = bufsm[nc] + buf[nc];
        li[lc] = new Tree(nc + 1, buf, bufsm, bufdata);
        return;
    }
    n2l[md] = P(lc, nc + 1);
    buf[nc] = sz[p] - sz[md];
    bufdata[nc] = data[p];
    bufsm[nc + 1] = bufsm[nc] + buf[nc];
    nc++;
    dfs(md, p);
    for (int d : g[p]) {
        if (d == b)
            continue;
        if (d == md)
            continue;
        lc++;
        nc = 0;
        n2l[d] = P(lc, 0);
        l2p[lc] = n2l[p];
        ldps[lc] = ldps[n2l[p].first] + 1;
        dfs(d, p);
    }
}