#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int failure[10], arrival, fail_cnt, answer;
string n_permutation;
void DFS(int key_cnt){
    if(n_permutation.size()){
       int cur = stoi(n_permutation);
       answer = min(answer, abs(cur - arrival) + key_cnt);
    }

    if(n_permutation.size() > 6){
        return;
    }
    for(int i = 0; i < 10; ++i){
        if(!failure[i]){
            n_permutation.push_back(i + '0');
            DFS(key_cnt + 1);
            n_permutation.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> arrival >> fail_cnt;

    for(int i = 0; i < fail_cnt; ++i){
        int n;
        cin >> n;
        failure[n]++;
    }
    if(arrival == 100) {
        cout << 0 << '\n';
        return 0;
    }
    answer = abs(100 - arrival);
    DFS(0);
    cout << answer;
    return 0;
}

// 설명(Brute Force)
// DFS로 풀었다. 이동가능한 채널이 총 0 <= Channel <= 5e5 이기 때문에
// 충분히 만들 수 있는 범위다.

// 풀고나서 다른 사람의 소스를 봤다.
// 속도차이가 0.3초씩이나 차이가 있길래 봤더니...
// 0~5e5까지 탐색을 하면서
// 각 자릿수가 고장난 버튼인지 아닌지 체크하면 조금더 빠른 방법으로 풀 수 있다.
// 나중에 추가 해야겠다.