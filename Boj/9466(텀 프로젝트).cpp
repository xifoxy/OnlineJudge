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

//����
//�����س´� Ǯ�̰� �ʹ� ��ȿ�����̶� Ǯ���� �ҽ��� �ô�.
//��������� ���� Ǯ�̿� ���������� �湮�迭������ �������.
//Ǯ�鼭 �����س� ����� �湮���� ���� ������ ���������� ������ �ε����� 1�� ������Ű�鼭
//1 2
//2 3
//3 4
//4 2
//5 3
//�̶�� ������ �ִٰ� ������ 1,2,3,4�� �湮�� 1�� �Ǵ°��̰� 5�� �湮�� 2�� �Ǵ°��̴�.
//����Ŭ�� �߰������� �湮�ڰ� ���� �ٸ��ٸ� �ű⼭ ���߰� ���ٸ� ī���� �ϴ� ����̴�.
//Ǯ�̰� �����ϱ⿡ ������ Ǯ���� ȿ������ ����������� ��ü�ߴ�.