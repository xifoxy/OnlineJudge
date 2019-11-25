#include <bits/stdc++.h>
using namespace std;
struct info{
    int s, e;
};
const int M = 2e5+1;
info table[M];
vector<info> heap;

int n;
void hPush(const info &a){
    heap.push_back(a);
    int idx = heap.size() - 1;
    
    while(idx != 0 && heap[idx].e < heap[(idx - 1) / 2].e){
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void hChange(const info &a){
    // 현재 시작해야 하는 강의 시간보다
    // 현재 힙에 들어 있는 강의 시간들의 종료시간이 더 낮다면 다 빼버린다.
    while(!heap.empty() && a.s >= heap.front().e){
        swap(heap.front(), heap.back());
        heap.pop_back();

        int idx = 0;
        int sz = heap.size() - 1;

        while(idx * 2 + 1 <= sz){
            int r = idx * 2 + 2;
            if(sz < r){
                if(heap[r - 1].e < heap[idx].e)
                    swap(heap[r - 1], heap[idx]);
                idx = r - 1;
            } else{
                int min_idx = heap[r].e < heap[r - 1].e ? r : r - 1;
                if(heap[min_idx].e < heap[idx].e)
                    swap(heap[min_idx], heap[idx]),
                    idx = min_idx;
                else break;
            }
        }
    }
    // 힙을 정리했으면 집어넣는다.
    hPush(a);
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &table[i].s, &table[i].e);

    // 시작 시간이 빠른 순서로 정렬한다.
    sort(table, table + n, [](const info &a, const info &b){
        return a.s < b.s;
    });

    int ans = 0;
    for(int i = 0; i < n; ++i){
        // 무조건 힙체인지로 보낸다.
        hChange(table[i]);
        // ans가 힙보다 작으면 갱신한다.
        if(ans < heap.size())
            ans = heap.size();
    }
    printf("%d\n", ans);
}

// 설명
// 힙으로 풀었다. 현재 시작해야될 강의 시간의 시작시간보다,
// 힙에 들어있는 강좌 종료 시간이 작은 경우 힙내 원소들을 제거하는 방법으로 풀었다.