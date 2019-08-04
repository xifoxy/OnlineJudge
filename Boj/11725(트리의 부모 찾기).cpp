#include <bits/stdc++.h>
using namespace std;
int parent[100001];
vector<vector<int>> vec;
int n, u, v;
void dfs(int pos) {
	for(auto &p : vec[pos]) {
		if(!parent[p]) {
			parent[p] = pos;
			dfs(p);
		}
	}
}
int main() {
	scanf("%d", &n);
	vec.resize(n + 1);
	for(int i = 0; i < n - 1; ++i) {
		scanf("%d%d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1);
	for(int i = 2; i <= n; ++i) {
		printf("%d\n", parent[i]);
	}
}

//설명
//예제만 보면 1번 예제가 이해가 안갈 수 있지만, 문제에서 친절히 루트가 1이라고 명시해줬다.
//단방향이 맞으나 구현하려면 양방향으로 입력해서 루트부터 탐색해야된다.
//이유는 입력이 a,b가 있다고 치면 어느게 부모인지 정보가 주어지지 않기 때문이다.