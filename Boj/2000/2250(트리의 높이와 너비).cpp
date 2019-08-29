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

// ����
// �׸��� ��� ��ġ�� �� ���캸�� ��Ģ���� ã�ƾ��Ѵ�.
// ���� ����, Y��(��)�� ��ȣ�� �� ���캸�� ���ʿ� ��ġ�ɼ��� �۰� �����ʿ� ��ġ�ɼ��� Ŀ����.

// KOI �úη� ���� �����̴�.
// "�̿� ���� ��Ģ�� ���� �����~ ��Ʈ ��尡 1�̰�"
// �̸��� ���� �� Ʋ�ȴ��� ��� ����ߴ� --