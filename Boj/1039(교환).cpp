#include <bits/stdc++.h>
using namespace std;

string num;
const int M = 1e6 + 1;
bool visit[M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int change;
    cin >> num >> change;

    queue<string> Q;
    Q.push(num);

    // 교환횟수 만큼 탐색
    while(change--){
        memset(visit, false, sizeof(visit));
        int sz = Q.size();

        // 큐의 크기만큼 돌아야 교환횟수를 구분할 수 있다.
        for(int i = 0; i < sz; ++i){
            string temp = Q.front();
            Q.pop();

            int t_sz = temp.size();

            // 교환 가능한 모든 경우를 탐색한다.
            for(int j = 0; j < t_sz; ++j){
                for(int k = j + 1; k < t_sz; ++k){
                    swap(temp[j], temp[k]);

                    // 중복되는 부분은 제외와, 0으로 시작하는 수는 제외한다.
                    if(!visit[stoi(temp)] && temp[0] != '0'){
                        visit[stoi(temp)] = true;
                        Q.push(temp);
                    }
                    swap(temp[j], temp[k]);
                }
            }
        }
    }

    int ans = -1;
    while(!Q.empty()){
        ans = max(stoi(Q.front()), ans);
        Q.pop();
    }
    cout << ans;
}

// 설명(BFS, Recursion)
// 재귀로 풀던 BFS로 풀던 어떤걸로 풀어도 상관없다.
// 교환 가능한 횟수만큼 모든 경우의 수를 구하여 큐에 넣고 큰 값을 출력하면 된다.