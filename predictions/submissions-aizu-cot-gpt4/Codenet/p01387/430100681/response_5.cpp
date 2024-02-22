//...

struct Centroid {
    int ParIndex, ParDepth, Deep;
    vector<int> node;
    Centroid(int idx, int dep, int deep)
        : ParIndex(idx), ParDepth(dep), Deep(deep) {}
    inline size_t size() { return (node.size()); }
    inline int &operator[](int k) { return (node[k]); }
    inline void Up(int& idx, int& dep) { idx = ParIndex; dep = ParDepth; }
};

//...
  
void BuildSubTreeSize() {
    //...
        if (~SubTreeSize[p.first]) {
            NextPath[p.first] = -1;
            for (auto &to : graph[p.first]) {
                if (p.second == to)
                    continue;
                SubTreeSize[p.first] += SubTreeSize[to];
                if (NextPath[p.first] == -1 ||
                    SubTreeSize[NextPath[p.first]] < SubTreeSize[to]) {
                    NextPath[p.first] = to;
                }
            }
        } else {
            s.push(p);
            SubTreeSize[p.first] = 1;
            for (auto &to : graph[p.first]) {
                if (p.second != to)
                    s.push({to, p.first});
            }
        }
    }
}

//...

inline int LCA(int a, int b) {
    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
    Information(a, TreeIdxA, TreeDepthA);
    Information(b, TreeIdxB, TreeDepthB);
    while (TreeIdxA != TreeIdxB) {
        if (Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
            Centroids[TreeIdxA].Up(TreeIdxA, TreeDepthA);
        } else {
            Centroids[TreeIdxB].Up(TreeIdxB, TreeDepthB);
        }
    }
    if (TreeDepthA > TreeDepthB)
        swap(TreeDepthA, TreeDepthB);
    return (Centroids[TreeIdxA][TreeDepthA]);
}

//...