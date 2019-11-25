#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
int n, a;

void hPush(int nVal){
    heap.push_back(nVal);

    int idx = heap.size() - 1;

    while(idx != 0 && heap[idx] > heap[(idx - 1) / 2]){
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}
int hPop(){
    if(heap.size() == 0) return 0;

    int ret = heap.front();
    swap(heap.front(), heap.back());
    heap.pop_back();

    int idx = 0;
    int sz = heap.size() - 1;
    while(idx * 2 + 1 <= sz){
        int r = idx * 2 + 2;

        if(sz < r){
            if(heap[r - 1] > heap[idx])
                swap(heap[r - 1], heap[idx]);
            idx = r - 1;
        } else{
            int min_idx = heap[r] > heap[r - 1] ? r : r - 1;
            if(heap[min_idx] > heap[idx])
                swap(heap[min_idx], heap[idx]),
                idx = min_idx;
            else break;
        }
    }

    return ret;
}

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        if(!a) printf("%d\n", hPop());
        else hPush(a);
    }
}

// 설명
// 힙의 기본 문제이니 구현법을 연습해보도록 하자.