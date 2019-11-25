#include <bits/stdc++.h>
using namespace std;

struct info{
    int num, next;
};
vector<info> vec;

const int M = 101;

bool visit[M];
int Prev[M];
int Next[M];
int d[M];
int n, k, a;

int main(){
    scanf("%d%d", &n, &k);

    for(int i = 1; i <= k; ++i)
        scanf("%d", &d[i]);

    // 원소의 Index를 리스트 형식으로 만든다.
    for(int i = k; i >= 1; --i){
        int num = d[i];
        Next[i] = Prev[num];
        Prev[num] = i;
    }

    int ans = 0;
    for(int i = 1; i <= k; ++i){
        // 다음 원소가 없을때 거리를 M으로 초기화 한다.
        if(!Next[i]) Next[i] = M;

        // 거리 정렬
        sort(vec.begin(), vec.end(), [](const info &a, const info &b){
            return a.next - k < b.next - k;
        });


        // 현재 인덱스의 숫자를 가져와서
        int cur = d[i];
        // 콘센트에 꽂혀있으면 다음 인덱스를 갱신해준다.
        if(visit[cur]){
            for(int idx = 0; idx < vec.size(); ++idx){
                if(vec[idx].num == cur){
                    vec[idx].next = Next[i];
                }
            }
            continue;
        
        // 그렇지 않다면, 거리가 가장 먼 플러그를 뽑는다.
        } else if(vec.size() == n){
            info t = vec.back();
            vec.pop_back();
            visit[t.num] = false;
            ans++;
        }
        
        // 그리고 꽂아주자.
        visit[cur] = true;
        vec.push_back({cur, Next[i]});

    }

    printf("%d\n", ans);
}

// 설명
// 콘센트에 들어가는 순서가 주어졌을대,
// 같은 원소간의 거리가 크거나(ex 1 2 3 3 3 2 1 .. 이 경우는 2의 거리보다 1의 거리가 더 크다) 
// 없는(ex. 1 2 3 2 3 .. 여기서 1은 없는 경우) 경우를 우선순위로 뽑기로 하고 풀면 된다.
// 우선순위 큐를 이용하려 했으나 머리가 잘 안굴러가는 관계로 Prev배열을 응용해서 풀었다.