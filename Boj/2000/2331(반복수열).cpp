#include <bits/stdc++.h>
using namespace std;
int n, m, idx = 1;
map<int, int> mp;
int dfs(int num, int p) {
	int sum = 0;
	while(num != 0) {
		sum += pow(num % 10, p);
		num /= 10;
	}
	if(mp[sum]) return mp[sum];
	mp[sum] = ++idx;
	return dfs(sum, p);
}
int main() {
	cin >> n >> m;
	mp[n] = 1;
	cout << dfs(n, m) - 1;
}

// 설명(DP)
// 문제에서 요구하는 규칙대로 숫자를 만들어 가는데,
// 반복구간이 나타나면 반복구간이 아닌 숫자들의 갯수를 출력하라고 한다.
// 57, 2 라고 입력되면
// 57, 74, 65, 61, [37), 58, 89, 145, 42, 20, 4, (16], 37, 58...
// 37부터 반복 시작 구간이고 16이 반복 구간 종료이니,
// 구간을 제외한 숫자는 4개이므로 답은 4가 된다.