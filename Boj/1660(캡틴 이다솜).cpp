#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 1;
int n, cnt = 1, tri = 1, ans;
int dp[MAX];
vector<int> triangle{1};
int main() {
	scanf("%d", &n);

    // 삼각수 정사면체로 쌓기(n번째 삼각수 구하는 공식 : n(n + 1) / 2)
	while(triangle.back() <= n) {
        // 삼각수
		tri += ++cnt;
        // 삼각수 쌓기
		triangle.push_back(triangle.back() + tri);
	}
	fill(&dp[1], &dp[MAX], MAX);
	
    // 메모이제이션
	for(int i = 0; i < triangle.size(); ++i) {
		if(triangle[i] > n) break;
		for(int j = triangle[i]; j <= n; ++j) {
			dp[j] = min(dp[j], dp[j - triangle[i]] + 1);
		}
	}
	printf("%d\n", dp[n]);
}

// 설명(DP)
// 주어진 대포로 삼각수를 쌓아서 만든 정사면체의 최솟값을 출력하는 문제이다.