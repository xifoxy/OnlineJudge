#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
int n;
void push_heap(int newValue) {
	heap.push_back(newValue);
	int idx = heap.size() - 1;
	while(idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
		swap(heap[(idx - 1) / 2], heap[idx]);
		idx = (idx - 1) / 2;
	}
}

void move_heap() {
	swap(heap.front(), heap.back());
	heap.pop_back();

	int idx = 0;
	int sz = heap.size() - 1;
	while(idx * 2 + 1 <= sz) {
		int r = idx * 2 + 2;
		if(sz < r) {
			if(heap[r - 1] < heap[idx])
				swap(heap[r - 1], heap[idx]);
			idx = r - 1;
		} else {
			int min_idx = heap[r] < heap[r - 1] ? r : r - 1;
			if(heap[min_idx] < heap[idx]) {
				swap(heap[min_idx], heap[idx]);
				idx = min_idx;
			} else return;
		} 
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int num;
		scanf("%d", &num);
		if(!num) {
			if(heap.size() == 0) puts("0");
			else {
				printf("%d\n", heap.front());
				move_heap();
			}
		} else push_heap(num);
	}
}

// 설명(Heap)
// 힙을 구현하는 기본문제이다.