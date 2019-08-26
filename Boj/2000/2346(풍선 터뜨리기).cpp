#include <bits/stdc++.h>
using namespace std;
struct node{
    int num, index;
};
int n, a;
int main(){
    scanf("%d", &n);

    deque<node> deq;

    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        deq.push_back({a, i + 1});
    }

    int cur = 0;
    for(int i = 0; i < n; ++i){
        int next = deq[cur].num;
        printf("%d ", deq[cur].index);
        deq.erase(deq.begin() + cur);

        // 데크의 전체 사이즈가 변했기 때문에 양수일경우 1빼준다.
        if(next > 0) next--;
        cur += next;

        // 데크 전체 사이즈(sz 대신 deq.size()를 넣어주면 오류가 생길 수 있다)
        // size함수는 unsigned int형이기 때문에 -값이 나오면 나머지 연산에서 이상한값이 나온다.
        // ex) -1 % 4? 4294967295 % 4 가 된다
        int sz = deq.size();
        if(sz){
            cur += cur >= 0 cur : sz + cur % sz;
            cur %= sz;
        }
    }
}

// 설명
// 인덱스 놀이를 하면 된다. 자료구조는 인접 배열로된것 중 아무거나 사용하면 되기에 데크를 썼다.

// 이동해야 하는 구간이 더하기 상태이면, 데크의 전체 크기에서 나머지 연산을 하면
// 인덱스 연산이 가능하지만, minus만큼 이동하게 되면
// 데크의 사이즈에서 나머지 연산 해준걸 더해줄 필요가 있다