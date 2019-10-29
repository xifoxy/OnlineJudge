#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int M = 51;
int n, m;
int board[M][M];
struct info {
    int x, y;
};
vector<info> vec, home;

// 거리 계산
int get_distance(const info &a, const info &b){
    return abs(b.x - a.x) + abs(b.y - a.y);
}

// 답 반환
int get_sum(vector<int> &permutation){
    int ans = 0;
    // 각 집의 좌표와
    for(int i = 0; i < home.size(); ++i){
        int temp = INF;
        // 조합으로 구해놓은 치킨 좌표들을 비교해서 가장 짧은 거리를
        for(int j = 0; j < permutation.size(); ++j){
            int idx = permutation[j];
            temp = min(temp, get_distance(home[i], vec[idx]));
        }
        // 더해준다.
        ans += temp;
    }
    return ans;
}

// 조합함수
int sol(int cur, vector<int> &permutation){
    int ret = INF;
    if(permutation.size() == m) return get_sum(permutation);

    for(int next = cur; next < vec.size(); ++next){
        permutation.push_back(next);
        ret = min(ret, sol(next + 1, permutation));
        permutation.pop_back();
    }
    return ret;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < n; ++y){
            scanf("%d", &board[x][y]);
            if(board[x][y] == 2)
                vec.push_back({x,y});
            if(board[x][y] == 1)
                home.push_back({x,y});
        }
    }
    vector<int> permutation;
    printf("%d\n", sol(0, permutation));
}

// 설명(Permutation)
// 문제를 제대로 읽이 않아서 어떻게 풀어야 하는지 한참 고민했다.
// 입력에  깨알같이 써져 있는데 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.
// 이 말은 Input으로 들어오는 2의 갯수가 13개를 넘지 않는다는 것이다.
// 그러니까 13개를 M개로 뽑는 경우의 수를 만드는 Permutation 함수를 구현할 줄 알아야 한다.