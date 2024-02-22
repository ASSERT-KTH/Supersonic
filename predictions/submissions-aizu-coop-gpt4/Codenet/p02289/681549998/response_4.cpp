#include <cstdio>
#include <queue>
#include <string>
using namespace std;

priority_queue<int> heap;

int main() {
	int key;
	string com;
	while (1) {
		scanf("%s", &com[0]);
		if (com == "end") break;
		if (com == "insert") {
			scanf("%d", &key);
			heap.push(key);
		} else {
			printf("%d\n", heap.top());
			heap.pop();
		}
	}
	return 0;
}