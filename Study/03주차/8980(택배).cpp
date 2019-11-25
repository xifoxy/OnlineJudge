#include <bits/stdc++.h>
using namespace std;
struct info{
	int Next, Box;
};

int n, c, m;
vector<info> vec[2001];
int dp[2001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> c >> m;

	for(int i = 0; i < m; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({b,c});

		// 도착지점이 가까운 순서부터 정렬
		sort(vec[a].begin(), vec[a].end(), [](const info &u, const info &v){
			return u.Next < v.Next;
		});
	}

	
	// Sum은 트럭에 실린 박스 수 이다.
	int ans = 0, sum = 0;
	for(int i = 1; i <= n; ++i){

		// 현재 위치에 배달가능한 물건이 있으면 갱신한다.
		sum -= dp[i];
		ans += dp[i];
		dp[i] = 0;

		// 현재 위치에서 보내야 하는 모든 물건을 다 싫는다.
		for(auto &p : vec[i]){
			dp[p.Next] += p.Box;
			sum += p.Box;
		}

		// 트럭에 용량을 초과했다면 현재 위치로 부터 가장 멀리 보내야 하는 물건들부터 내린다.
		for(int j = n; j > i && sum > c; --j){
			
			// 일부만 내려서 트럭의 최대치인 C를 맞출수 있다면 갱신하고 멈춘다.
			if(sum - dp[j] <= c){
				dp[j] -= (sum - c);
				sum -= (sum - c);
				break;
			}

			// 내려버리기
			sum -= dp[j];
			dp[j] = 0;
		}
	}
	cout << ans;
}

// 설명
// 이 문제의 핵심은, 도착지점이 가장 빠른순서부터 정렬 하는 것이다.
// 즉, 현재 위치로부터 가장 가까운 곳에 배달하는게 가장 많이 배달할 수 있다