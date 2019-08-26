#include <bits/stdc++.h>
using namespace std;
int n, d[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= 100000; ++i) {
		for(int j = 1; j * j <= i; ++j) {
			if(d[i] > d[i - j * j] + 1 || !d[i])
				d[i] = d[i - j * j] + 1;
		}
	}
	cout << d[n];
}

// 설명(DP)
// N을 제곱의 합(제곱의 개수)을 최소로 하는 문제이다.
// 쉬우니 점화식 보고 이해해보자.