#include <bits/stdc++.h>
using namespace std;
int d[501][501], n, ans;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			cin >> d[i][j];
			if(i) {
				if(!j) d[i][j] += d[i - 1][j];
				else if(j == i) d[i][j] += d[i - 1][j - 1];
				else d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
			}
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans << '\n';
}

//어렵게 생각할 필요가 없다.
//N줄에 있는 정수는 인덱스 0과 N-1에 대한 예외 처리만 해두도록 하면 되고
//나머지는 바로위에것과 그 옆에것을 더했을때 최대값을 쌓아내려가면된다.