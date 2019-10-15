#include <bits/stdc++.h>
using namespace std;
const int M = 1e4;
bool isprime[M];
bool visit[M];
struct info{
    int num, cnt;
};

int main(){
    for(int i = 2; i < M; ++i){
        if(!isprime[i]){
            for(int j = i * i; j < M; j+=i)
                isprime[j] = true;
        }
    }

    int tc;
    scanf("%d", &tc);
    while(tc--){
        memset(visit, false, sizeof(visit));
        int start, end;
        scanf("%d%d", &start, &end);

        queue<info> Q;
        Q.push({end, 0});
        bool ans = false;
        visit[end] = true;

        while(!Q.empty()){
            info temp = Q.front();
            Q.pop();
            if(temp.num == start){
                printf("%d\n", temp.cnt);
                ans = true;
                break;
            }
            
            for(int MOD = 10; MOD <= M; MOD *= 10){
                // 1,10,100,1000 순서로 자릿수를 초기화 해준다.
                // ex) 8179라고 하면
                // 8170, 8109, 8079, 0179
                int current = temp.num - (temp.num % (MOD)) + (temp.num % (MOD / 10));
                for(int PLUS = 0; PLUS < MOD; PLUS += (MOD / 10)){
                    // 초기화 해준 자릿수를 더해가면서 확인한다.
                    int next = current + PLUS;
                    if(next >= MOD / 10 && !visit[next] && !isprime[next]){
                        Q.push({next, temp.cnt + 1});
                        visit[next] = true;
                    }
                }
            }
        }
        if(!ans) puts("Impossible");
    }
}

// 설명(Sieve of Eratosthenes, BFS)
// 1. 우선 1만보다 작은 모든 소수를 구한다.
// 2. BFS한다.

// 각 자릿수를 조정해서 소수가 만들어지는지 확인하면서 큐에 넣으면 된다.