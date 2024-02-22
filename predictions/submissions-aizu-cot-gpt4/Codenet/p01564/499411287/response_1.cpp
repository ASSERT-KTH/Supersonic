// Define a memory pool with a fixed size.
#define MAX_POOL_SIZE 200000
Tree pool[MAX_POOL_SIZE];
int poolCnt = 0;

// In the Tree struct, replace 'new Tree(...)' with a function that gets a Tree from the memory pool.
Tree* getTreeFromPool(int sz, int hev[], int hevsm[], int data[]) {
    Tree* tree = &pool[poolCnt++];
    // Initialize tree with the provided parameters...
    return tree;
}

// Replace 'new Tree()' with 'getTreeFromPool()'.
l = getTreeFromPool(md, hev, hevsm, data);
r = getTreeFromPool(sz - md, hev + md, hevsm + md, data + md);