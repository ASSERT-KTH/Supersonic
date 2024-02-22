class MemoryPool {
public:
    // Constructor to initialize the memory pool
    MemoryPool(size_t size) {
        // Allocate a block of memory for the pool
        pool = new char[size * sizeof(Tree)];

        // Initialize the free list
        for (size_t i = 0; i < size; i++) {
            freeList.push_back(&pool[i * sizeof(Tree)]);
        }
    }

    // Destructor to free the memory pool
    ~MemoryPool() {
        delete[] pool;
    }

    // Allocate a node from the memory pool
    Tree* alloc() {
        // Get a free node from the pool
        Tree* node = (Tree*)freeList.back();
        freeList.pop_back();

        // Return the node
        return node;
    }

    // Deallocate a node back to the memory pool
    void dealloc(Tree* node) {
        // Add the node back to the free list
        freeList.push_back((char*)node);
    }

private:
    char* pool;
    vector<char*> freeList;
};