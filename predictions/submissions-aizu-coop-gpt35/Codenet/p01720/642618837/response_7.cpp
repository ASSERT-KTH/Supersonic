#include <iostream>
#include <vector>
#define INF (1 << 23)

// Custom Queue Implementation
template <typename T, int SIZE>
class Queue {
private:
    T data[SIZE];
    int front, rear, count;

public:
    Queue() : front(0), rear(0), count(0) {}

    void push(T element) {
        if (count == SIZE) {
            // Queue is full, handle the overflow case
            return;
        }
        data[rear] = element;
        rear = (rear + 1) % SIZE;
        count++;
    }

    T pop() {
        if (count == 0) {
            // Queue is empty, handle the underflow case
            return T();
        }
        T frontElement = data[front];
        front = (front + 1) % SIZE;
        count--;
        return frontElement;
    }

    bool empty() const {
        return count == 0;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, s, t, u, v;
    std::cin >> N >> M >> s >> t;
    s--;
    t--;

    std::vector<std::vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v;
        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
    }

    std::vector<int> d1(N, INF);
    d1[s] = 0;
    std::vector<int> d2(N, INF);
    d2[t] = 0;

    Queue<int, 10000> que;  // Custom queue with fixed size
    que.push(s);
    while (!que.empty()) {
        int node = que.pop();
        for (int i = 0; i < G[node].size(); i++) {
            int neighbor = G[node][i];
            if (d1[neighbor] == INF) {
                d1[neighbor] = d1[node] + 1;
                que.push(neighbor);
            }
        }
    }

    que.push(t);
    while (!que.empty()) {
        int node = que.pop();
        for (int i = 0; i < G[node].size(); i++) {
            int neighbor = G[node][i];
            if (d2[neighbor] == INF) {
                d2[neighbor] = d2[node] + 1;
                que.push(neighbor);
            }
        }
    }

    int shortest = d1[t];
    std::vector<int> r1(shortest - 1, 0);
    for (int i = 0; i < N; i++) {
        if (d1[i] < shortest - 1) {
            r1[d1[i]]++;
        }
    }

    std::vector<int> r2(shortest - 1, 0);
    for (int i = 0; i < N; i++) {
        if (d2[i] < shortest - 1) {
            r2[d2[i]]++;
        }
    }

    long long ret = 0;
    for (int i = 0; i < shortest - 1; i++) {
        ret += 1LL * r1[i] * r2[shortest - i - 2];
    }

    std::cout << ret << "\n";
    return 0;
}