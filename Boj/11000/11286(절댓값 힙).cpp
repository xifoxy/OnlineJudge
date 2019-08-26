#include <bits/stdc++.h>
using namespace std;
void heap_push(int newValue, vector<int> &heap) {
	heap.push_back(newValue);
	int idx = heap.size() - 1;
	while(idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
		swap(heap[(idx - 1) / 2], heap[idx]);
		idx = (idx - 1) / 2;
	}
}

void heap_move(vector<int> &heap, bool isminus = false) {
	int num = heap.front();
	printf("%d\n", isminus ? -num : num);
	swap(heap.front(), heap.back());
	heap.pop_back();

	int idx = 0;
	while(idx * 2 + 1 < heap.size()) {
		int next = idx * 2 + 1;
		if(next + 1 < heap.size()) {
			int minDex = heap[next] > heap[next + 1] ? next + 1 : next;
			if(heap[idx] < heap[minDex]) return;
			swap(heap[idx], heap[minDex]);
			idx = minDex;
		} else {
			if(heap[next] < heap[idx])
				swap(heap[next], heap[idx]);
			idx = next;
		}
	}
}

int main() {
	vector<int> mheap, pheap;
	int n, newValue;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &newValue);
		if(newValue) 
			newValue < 0 ? heap_push(-newValue, mheap) : heap_push(newValue, pheap);
		else {
			if(mheap.size() && pheap.size()) {
				mheap.front() <= pheap.front() ? heap_move(mheap, true) : heap_move(pheap);
			} else if(mheap.size()) heap_move(mheap, true);
			else if(pheap.size()) heap_move(pheap);
			else puts("0");
		}
	}
}

// 설명(힙)
// 힙하나로 구현하려면 엄청 까다로워진다.
// 하지만 힙을 두개로 나누면 쉽다.

// 1. 음수힙과 양수힙 두개를 만든다.
// 2. 0이 입력 되었을때 항상 음수힙과 양수힙의 front를 비교한다.
// 3. 출력한다.