#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
int n, a[M], tc;
bool visit[M], d[M];
int dfs(int pos) {
	d[pos] = true;
	int ret = 0;
	int next = a[pos];
	if(d[next]) {
		if(!visit[next]) {
			for(int i = next; i != pos; i = a[i]) ret++;
			ret++;
		}
	} else ret += dfs(next);
	visit[pos] = true;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> tc;
	while(tc--) {
		memset(a, 0, sizeof(a));
		memset(d, false, sizeof(d));
		memset(visit, false, sizeof(visit));
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];

		int ans = 0;
		for(int i = 1; i <= n; ++i)
			if(!visit[i]) ans += dfs(i);
		cout << n - ans << '\n';
	}
}

//설명
//생각해냈던 풀이가 너무 비효율적이라서 풀었던 소스를 봤다.
//결론적으론 이전 풀이와 유사하지만 방문배열구현이 구데기다.
//풀면서 생각해낸 방법은 방문하지 않은 정점을 만날때마다 임의의 인덱스를 1씩 증가시키면서
//1 2
//2 3
//3 4
//4 2
//5 3
//이라는 구조가 있다고 했을때 1,2,3,4는 방문자 1이 되는것이고 5는 방문자 2가 되는것이다.
//사이클을 발견했을때 방문자가 서로 다르다면 거기서 멈추고 같다면 카운팅 하는 방식이다.
//풀이가 유사하기에 예전에 풀었던 효율적인 구현방법으로 대체했다.