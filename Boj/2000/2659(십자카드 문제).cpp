#include <bits/stdc++.h>
using namespace std;
int dp[10'000], cnt = 2;
char a;
int main() {
	dp[1111] = 1;
	string gg;
	for(int i = 1112; i <= 9999; ++i) {
		int t = i;
		bool ans = true;
		while(t > 0) {
			if(t % 10 == 0) ans = false;
			t /= 10;
		}
		if(!ans || dp[i]) continue;
		dp[i] = cnt;
		gg = to_string(i);
		for(int j = 0; j < 3; ++j) {
			gg = gg[3] + gg;
			gg.pop_back();
			dp[stoi(gg)] = cnt;
		}
		cnt++;
	}
	gg = "";
	for(int i = 0; i < 4; ++i) {
		cin >> a;
		gg.push_back(a);
	}
	cout << dp[stoi(gg)] << '\n';
}

// 설명(Brute Force)

// 수식을 넣기 귀찮아서 그냥 문자열을 이용했다.
// 우선 예외처리로 0이 들어간 숫자와 방문했던 숫자는 걸러주고
// 숫자를 빙글빙글 돌려가면서 번호 매기면 된다.