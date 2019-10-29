#include <bits/stdc++.h>
using namespace std;
struct info{
    int cnt, clip;
};
const int M = 1e3;
bool dp[M + 1][M + 1];
int n;
int main(){
    scanf("%d", &n);

    queue<info> Q;
    Q.push({1,0});
    dp[1][0] = 0;

    
    int cmd_time = 0;
    bool cmp = true;

    // 2중 반복문으로 구현한 이유는, 연산 시간을 구분하기 위함이다.
    while(!Q.empty() && cmp){
        int sz = Q.size();

        for(int i = 0; i < sz && cmp; ++i){
            info t = Q.front();
            Q.pop();

            if(t.cnt == n) {
                printf("%d\n", cmd_time);
                cmp = false;
                break;
            }


            // 1. 클립보드에 저장
            Q.push({t.cnt, t.cnt});

            // 2. 현재 클립보드에 있는 값 붙여넣기
            // 이모티콘의 길이가 1000이 넘는것은 굳이 갱신할 필요가 없다.
            int len = t.cnt + t.clip;
            if(len <= M && !dp[len][t.clip]){
                Q.push({len, t.clip});
                dp[len][t.clip] = true;
            }

            // 3. 현재 화면의 이모티콘 하나 삭제
            // 2번에 의해서 1000이 넘는 숫자는 들어가지 않기 때문에,
            // 1보다 큰지만  확인하면 된다.
            if(t.cnt > 1 && !dp[t.cnt - 1][t.clip]){
                Q.push({t.cnt - 1, t.clip});
                dp[t.cnt-1][t.clip] = true;
            }
        }
        // 연산 시간 증감
        cmd_time++;
    }
}

// 설명(BFS, DP)
// 메모배열을 잘 활용해야 한다.

// dp[이모지.length][current clip] 형태로 메모이제이션을 해나가면 된다.