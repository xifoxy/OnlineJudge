#include <bits/stdc++.h>
using namespace std;
string num;
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		cin >> num;
		if((num.back() - '0') % 2) cout << "odd";
		else cout << "even";
		cout << '\n';
	}
}

// 설명
// 왜 40프로지?
// 이해가 되지않는 정답률이다.
// 주어진 수의 범위는 1 <= num <= 10^60 이다.
// 홀짝의 상태는 1의 자리 숫자만 확인하면 답이 나오니
// 문자열로 입력받고 마지막 숫자만 확인해주면 된다.