#include <bits/stdc++.h>
using namespace std;
int n, num;
long long ans;
vector<int> heap;

// �ּ���
void heap_push(int pb) {
	heap.push_back(pb);
	int index = heap.size() - 1;
	while(index > 0 && heap[(index - 1) / 2] > heap[index]) {
		swap(heap[(index - 1) / 2], heap[index]);
		index = (index - 1) / 2;
	}
}

// �� ���� ����
void move_heap() {
	swap(heap.back(), heap.front());
	heap.pop_back();
	int idx = 0, sz = heap.size();
	while(sz > idx * 2 + 1) {
		int r = idx * 2 + 2;
		if(r >= sz) {
			if(heap[r - 1] < heap[idx])
				swap(heap[r - 1], heap[idx]);
			idx = r;
		} else {
			int min_idx = heap[r] < heap[r - 1] ? r : r - 1;
			if(heap[idx] > heap[min_idx]) {
				swap(heap[idx], heap[min_idx]);
				idx = min_idx;
			} else return;
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &num);
		heap_push(num);
	}

	int sz = heap.size() - 1;

	for(int i = 0; i < sz; ++i) {
       int sz = heap.size() - 1;

	for(int i = 0; i < sz; ++i) {
        // ���� ���� ���ڸ� �̰�
		int temp = heap.front();
        // �����ϰ� �����Ѵ�.
		move_heap();
        // �׸��� �ٽ� �ϳ� �̾Ƽ� ���ο� ���ڸ� �����
		temp += heap.front();
        // �����ϰ� �����Ѵ�.
		move_heap();
        // ���� ������� ���ڶ��� �����ϰ� �����Ѵ�.
		heap_push(temp);
		ans += temp;
	}
	printf("%lld\n", ans);
	}
	printf("%lld\n", ans);
}

// ����(Priority Queue, Heap)
// ó�� ������ �о����� �����ߴ�.(���� ��û�ؼ� ���ذ� ������.)
// ������ ���� �ΰ��� �������� ���� ���� ���� �ΰ��� ��ġ�°� ȿ�����̶�°� �˼� �ִ�.
// ���� �ΰ��� �̰� ��ĥ������ ������ �ٲ�� ������ ������ �������� �ʿ䰡 �ִ�.
// �׷��� logN�� ������ ������ �ڷᱸ���� �̿��ϸ� �ȴ�.