#include <bits/stdc++.h>
using namespace std;
int n, num;
long long ans;
vector<int> heap;

// 최소힙
void heap_push(int pb) {
	heap.push_back(pb);
	int index = heap.size() - 1;
	while(index > 0 && heap[(index - 1) / 2] > heap[index]) {
		swap(heap[(index - 1) / 2], heap[index]);
		index = (index - 1) / 2;
	}
}

// 힙 삭제 구현
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
        // 제일 작은 숫자를 뽑고
		int temp = heap.front();
        // 삭제하고 정렬한다.
		move_heap();
        // 그리고 다시 하나 뽑아서 새로운 숫자를 만들고
		temp += heap.front();
        // 삭제하고 정렬한다.
		move_heap();
        // 새로 만들어진 숫자또한 갱신하고 정렬한다.
		heap_push(temp);
		ans += temp;
	}
	printf("%lld\n", ans);
}

// 설명(Priority Queue, Heap)
// 처음 문제를 읽었을때 난해했다.(나는 멍청해서 이해가 느리다.)
// 임의의 숫자 두개를 합쳤을때 가장 작은 숫자 두개를 합치는게 효율적이라는걸 알수 있다.
// 숫자 두개를 뽑고 합칠때마다 순위가 바뀌기 때문에 순서를 갱신해줄 필요가 있다.
// 그래니 logN로 정렬이 가능한 자료구조를 이용하면 된다.