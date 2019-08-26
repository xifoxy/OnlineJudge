#include <bits/stdc++.h>
using namespace std;
string A, B;
int f(int cur) {
	int ret = 0;
	for(int i = 0; i < A.size(); ++i) {
		if(A[i] != B[i + cur])
			ret++;
	}
	return ret;
}
int main() {
	cin >> A >> B;
	int ans = f(0);
	for(int i = 0; i < B.size() - A.size(); ++i)
		ans = min(ans, f(i + 1));
	cout << ans << '\n';
}

// 설명
// 겹치는 부분이 최대한 많은 곳이 답이 된다.