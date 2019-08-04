#include <bits/stdc++.h>
using namespace std;
void heap_push(int newValue, vector<int> &heap)  {
	heap.push_back(newValue);
	int idx = heap.size() - 1;
	while(idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
		swap(heap[(idx - 1) / 2], heap[idx]);
		idx = (idx - 1) / 2;
	}
}
void heap_move(vector<int> &heap) {
	if(heap.size() == 0) {
		puts("0");
		return;
	}
	printf("%d\n", heap.front());
	swap(heap.front(), heap.back());
	heap.pop_back();

	int idx = 0;
	while(idx * 2 + 1 < heap.size()) {
		int next = idx * 2 + 1;
		if(next + 1 < heap.size()) {
			int maxDex = heap[next] > heap[next + 1] ? next : next + 1;
			if(heap[maxDex] < heap[idx]) return;

			swap(heap[maxDex], heap[idx]);
			idx = maxDex;
		} else {
			if(heap[next] > heap[idx])
				swap(heap[next], heap[idx]);
			idx = next;
		}
	}
}
int main() {
	vector<int> heap;
	int order;
	scanf("%d", &order);
	for(int i = 0; i < order; ++i) {
		int num;
		scanf("%d", &num);
		if(num) heap_push(num, heap);
		else heap_move(heap);
	}
}

// 설명(힙)
// 1. 구현하고
// 2. 출력한다