#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Faster input reading function
inline void reader(int& x) {
    scanf("%d", &x);
}

// Custom queue implementation
template<typename T>
class CustomQueue {
public:
    CustomQueue(int capacity) {
        arr = new T[capacity];
        front = rear = 0;
    }

    ~CustomQueue() {
        delete[] arr;
    }

    void push(T x) {
        arr[rear++] = x;
    }

    T front() {
        return arr[front];
    }

    void pop() {
        front++;
    }

    bool empty() {
        return front == rear;
    }

private:
    T* arr;
    int front, rear;
};

int main() {
    int n, m, q;
    reader(n);
    reader(m);
    reader(q);

    vector<vector<int>> E(n);

    for (int i = 0; i < m; i++) {
        reader(u[i]);
        reader(v[i]);
        u[i]--;
        v[i]--;
        E[u[i]].push_back(v[i]);
        E[v[i]].push_back(u[i]);
    }

    CustomQueue<int> que(n);
    vector<int> d(n, -1);
    d[0] = 0;
    que.push(0);

    while (!que.empty()) {
        int p = que.front();
        que.pop();

        for (int v : E[p]) {
            if (d[v] == -1) {
                d[v] = d[p] + 1;
                que.push(v);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (d[u[i]] > d[v[i]]) {
            swap(u[i], v[i]);
        }
    }

    E.clear();

    vector<bool> b(m, false);

    for (int i = 0; i < q; i++) {
        reader(r[i]);
        r[i]--;
        b[r[i]] = true;
    }

    vector<bool> ok(n, false);
    ok[0] = true;

    for (int i = 0; i < m; i++) {
        if (!b[i] && d[v[i]] - d[u[i]] == 1) {
            E[u[i]].push_back(v[i]);
        }
    }

    que.push(0);

    while (!que.empty()) {
        int p = que.front();
        que.pop();

        for (int v : E[p]) {
            if (d[v] > d[p] && !ok[v]) {
                ok[v] = true;
                que.push(v);
            }
        }
    }

    vector<int> ans(q);

    for (int i = q - 1; i >= 0; i--) {
        ans[i] = n - cnt;
        if (d[v[r[i]]] - d[u[r[i]]] == 1 && !ok[v[r[i]]]) {
            E[u[r[i]]].push_back(v[r[i]]);
            if (ok[u[r[i]]]) {
                cnt++;
                ok[v[r[i]]] = true;
                que.push(v[r[i]]);
                while (!que.empty()) {
                    int p = que.front();
                    que.pop();

                    for (int v : E[p]) {
                        if (d[v] > d[p] && !ok[v]) {
                            ok[v] = true;
                            que.push(v);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}