#include <bits/stdc++.h>
using namespace std;
const int MX = 10;
int a[MX][MX], n, ans = 100000000;
bool visited[MX];
void tsp(int pos, int cost, int visit, int start) {
	if(visit == 1) {
		if(a[pos][start]) {
			ans = min(cost + a[pos][start], ans);
		}
		return;
	}
	for(int i = 0; i < n; ++i) {
		if(!visited[i] && a[pos][i] && i != start) {
			cost += a[pos][i];
			visited[i] = true;
			tsp(i, cost, visit - 1, start);
			cost -= a[pos][i];
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < n; ++i) {
		tsp(i, 0, n, i);
	}
	printf("%d\n", ans);
}

//����
//������ 10�̴�. �̺��� Ŀ���� ��Ž���� Ǯ������ ���� ��찡 ����.
//�׶��� �ִܰŸ� �˰��� �߿� �ϳ��� �����ؾ��Ѵ�.
//���������� ������ ��ߵ��ð� �������� �ʾұ� ������ ��� ��츦 �� Ž���ؾ��Ѵ�.
//0�̸� �湮�� �Ұ��ϴٴ� ������ʸ� Ȯ���ؾ��ϰ�, ����ߴ� ���ø� �ٽ� ���ư��� �ϱ� ������
//��� ���ǹ��� �ʿ��ϴ� �ݺ��� ���ο� ���ǰ� �湮�ؾ��� ���ð� N - 1���� �Ǿ������� �� ���캸��.