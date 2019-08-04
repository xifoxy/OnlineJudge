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

//#Ž��(DFS)

//����������� ����
//����� �������� ����µ�
//������Ʈ�� ����Ŭ �κ��� ã����� �̾߱��.
//�׷��ϱ� �׳� ����Ŭ�� ã�Ƽ� ����ϸ� �ȴ�.
//DFS�Լ��� �湮�迭 �ΰ��� ������ ��ºκ��� �� ����.