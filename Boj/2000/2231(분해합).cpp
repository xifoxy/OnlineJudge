#include <bits/stdc++.h>
using namespace std;
int n, num;
int main() {
	bool ans = false;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		num = i;
		int t = i;
		while(t > 0) {
			num += (t % 10);
			t /= 10;
		}
		if(num == n) {
			num = i;
			ans = true;
			break;
		}
	}
	if(ans) printf("%d\n", num);
	else puts("0");
}

//설명
//주어진 수의 원본 분해합을 찾는 문제이다.
//범위가 1 <= N <= 1e6이기에 원본 분해합이 만들어지는지 체크 하면 된다.
