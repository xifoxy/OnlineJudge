#include <bits/stdc++.h>
using namespace std;

int dx[]{-1,-2,-2,-1,1,2,2,1};
int dy[]{-2,-1,1,2,-2,-1,1,2};

bool visit[8][8];

vector<string> st;
int main(){
    bool ans = true;
    string next, cur, fir;
    for(int i = 0; i < 36; ++i){
        cin >> cur;
        st.push_back(cur);
    }

    // 2번 조건을 위해 시작 좌표를 제일 마지막에 넣는다.
    st.push_back(st.front());
    for(int i = 1; i < 37; ++i){
        if(!ans) continue;

        int cx = st[i-1][1] - '1';
        int cy = st[i-1][0] - 'A';
        ans = false;

        // 나이트가 갈수 있는 8가지 방향 탐색
        for(int direction = 0; direction < 8; ++direction){
            int nx = cx + dx[direction];
            int ny = cy + dy[direction];

            // 현재 좌표에서 다음 좌표로 이동 할수 있고, 방문하지 않았던 곳이면 된다.
            if(nx + '1' == st[i][1] && ny + 'A' == st[i][0] && !visit[nx][ny]){
                visit[nx][ny] = true;
                ans = true;
            }
        }
    }
    cout << (ans ? "Valid" : "Invalid");
}

// 설명
// 조건이 2가지 조건만 잘 지키면 된다.
// 1. 방문했던 곳이면 오답이다.
// 2. 마지막으로 주어진 좌표에서 시작좌표로 갈 수 없으면 오답이다.