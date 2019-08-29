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

// ����(Sort)
// �־��� �޸𸮴� 10Mb�̱� ������ ���� �� �޾Ƽ� �����ϱ⿣ �ʹ� �ָ��ϴ�.
// �׷� ������ ������ ��� �ϴµ�, �����ؾ��� ���ڵ��� ���� ������ N���� Ŀ���� �����ϰ� ���� �ȴ�.
// ����Ʈ�� �̿��ص� ������ ���� Heap�� �̿��ߴ�.

// ����Ʈ�� �̿��Ϸ��� �迭�� ���̰� N���� Ŀ���� ���� ������������ �����ϰ� ���� �ڿ� �ִ� ���Ҹ� ���� �ȴ�.