#include <bits/stdc++.h>
using namespace std;
int d[101], n;
bool visit[101], visited[101];
vector<int> ans;
void dfs(int x) {
	visit[x] = true;
	int next = d[x];
	if(visit[next]) {
		if(!visited[next]) {
			for(int i = next; i != x; i = d[i]) {
				ans.push_back(i);
			}
			ans.push_back(x);
		}
	} else dfs(next);
	visited[x] = true;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &d[i + 1]);
	}
	for(int i = 1; i <= n; ++i)
		if(!visit[i]) dfs(i);
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for(auto &p : ans) {
		printf("%d\n", p);
	}
}

//#탐색(DFS)

//저어어어어어엉말 쉽다
//뭐라고 주절주절 써놨는데
//컴포넌트의 싸이클 부분을 찾으라는 이야기다.
//그러니까 그냥 싸이클을 찾아서 출력하면 된다.
//DFS함수에 방문배열 두개를 가지고 노는부분을 잘 보자.