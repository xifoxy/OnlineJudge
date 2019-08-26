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

//설명
//사실 선형 자료구조를 이용하려고 했지만 방법이 떠오르지 않아서 map을 이용했다.
//문제의 규칙은 간단하다. 반복구간이 발견되면 
//반복구간이 아닌 숫자의 갯수를 카운팅해서 출력하면 된다.