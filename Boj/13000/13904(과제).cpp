#include <bits/stdc++.h>
using namespace std;
struct info{
    int End, Score;
};
const int M = 1e3+1;
vector<int> heap;
info table[M];
int n;
void hPush(int nVal){
    heap.push_back(nVal);

    int idx = heap.size() - 1;

    while(idx != 0 && heap[idx] < heap[(idx - 1) / 2]){
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}
int hPop(){
	int ret = heap.front();
    swap(heap.front(), heap.back());
    heap.pop_back();

    int idx = 0;
    int sz = heap.size() - 1;
    while(idx * 2 + 1 <= sz){
        int r = idx * 2 + 2;

        if(sz < r){
            if(heap[r - 1] < heap[idx])
                swap(heap[r - 1], heap[idx]);
            idx = r - 1;
        } else{
            int min_idx = heap[r] < heap[r - 1] ? r : r - 1;
            if(heap[min_idx] < heap[idx])
                swap(heap[min_idx], heap[idx]),
                idx = min_idx;
            else break;
        }
    }
	return ret;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> table[i].End >> table[i].Score;
	}

	sort(table, table + n, [](const info &a, const info &b){
		return a.End < b.End;
	});

	int ans = 0;
	for(int i = 0; i < n; ++i){
		int Sc = table[i].Score;
        // 과제 마감일이 힙보다 큰 경우 더해준다.
		if(table[i].End > heap.size()){
			hPush(Sc);
			ans += Sc;

        // 위에 포함되지 않으면 과제 마감일 <= 힙의 크기가 된다.
        // 그러니 제일 작은 점수가 되는 과제를 빼버리고, 넣는다.
		} else if(heap.front() < Sc){
			ans -= hPop();
			ans += Sc;
			hPush(Sc);
		}
	}

	cout << ans;
}

// 설명
// 힙으로 풀었다. 아이디어는, 과제마감일 < 힙의 크기 인 경우를 생각해보면 된다.