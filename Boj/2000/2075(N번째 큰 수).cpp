#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
int n, num;
void push_heap(int newValue) {
	heap.push_back(newValue);
	int idx = heap.size() - 1;
	while(idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
		swap(heap[idx], heap[(idx - 1) / 2]);
		--idx /= 2;
	}
}
void move_heap() {
	swap(heap.front(), heap.back());
	heap.pop_back();
	int sz = heap.size() - 1;
	int idx = 0;

	while(idx * 2 + 1 <= sz) {
		int r = idx * 2 + 2;
		if(r > sz) {
			if(heap[idx] > heap[r - 1])
				swap(heap[idx], heap[r - 1]);
			return;
		} else {
			int min_idx = heap[r] < heap[r - 1] ? r : r - 1;
			if(heap[idx] > heap[min_idx]) {
				swap(heap[min_idx], heap[idx]);
				idx = min_idx;
			} else return;
		}
	}
}
int main() {
	heap.reserve(1501);
	scanf("%d", &n);
	for(int i = 0; i < n * n; ++i) {
		scanf("%d", &num);
		if(heap.size() < n)
			push_heap(num);
		else {
			if(heap.front() < num) {
				move_heap();
				push_heap(num);
			}
		}
	}
	printf("%d\n", heap.front());
}

// 설명(Sort)
// 주어진 메모리는 10Mb이기 때문에 모든걸 다 받아서 정렬하기엔 너무 애매하다.
// 그럼 범위의 제한을 줘야 하는데, 정렬해야할 숫자들을 담은 구조가 N보다 커지면 정렬하고 빼면 된다.
// 퀵소트를 이용해도 되지만 나는 Heap을 이용했다.

// 퀵소트를 이용하려면 배열의 길이가 N보다 커질때 마다 내림차순으로 정렬하고 제일 뒤에 있는 원소를 빼면 된다.