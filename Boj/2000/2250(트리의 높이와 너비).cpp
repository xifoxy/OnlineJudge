#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 1;
int n, dep;
bool parent[MAX];
vector<int> vertex[MAX], adj[MAX];
void inorder(int pos, int depth, int &column) {
	dep = max(depth, dep);
	if(pos == -1) return;
	inorder(adj[pos][0], depth + 1, column);
	vertex[depth].push_back(++column);
	inorder(adj[pos][1], depth + 1, column);
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int p, l, r;
		scanf("%d%d%d", &p, &l, &r);
		adj[p].push_back(l);
		adj[p].push_back(r);
		if(l != -1) parent[l] = 1;
		if(r != -1) parent[r] = 1;
	}
	int p = 0;
	for(int i = 1; i <= n; ++i) {
		if(!parent[i]) {
			p = i;
			break;
		}
	}
	int lv = 1, ans = 1, col = 0;
	inorder(p, 1, col);
	for(int i = 1; i <= dep; ++i) {
		if(vertex[i].size()) {
			int sum = vertex[i].back() - vertex[i].front() + 1;
			if(sum > ans) {
				ans = sum;
				lv = i;
			}
		}
	}
	printf("%d %d\n", lv, ans);
}

// 설명
// 그림의 노드 배치를 잘 살펴보며 규칙부터 찾아야한다.
// 별거 없다, Y축(열)의 번호를 잘 살펴보면 왼쪽에 배치될수록 작고 오른쪽에 배치될수록 커진다.

// KOI 시부레 농간의 장인이다.
// "이와 같은 규칙에 따라 블라블라~ 루트 노드가 1이고"
// 이말에 낚여 왜 틀렸는지 계속 고민했다 --