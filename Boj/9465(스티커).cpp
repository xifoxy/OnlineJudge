#include <bits/stdc++.h>
using namespace std;
int n, a[2][100001], d[2][100001], tc;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> tc;
	while(tc--) {
		cin >> n;
		memset(d, 0, sizeof(d));
		for(int i = 0; i < 2; ++i)
			for(int j = 1; j <= n; ++j)
				cin >> a[i][j];

		d[0][1] = a[0][1];
		d[1][1] = a[1][1];
		for(int i = 2; i <= n; ++i) {
			d[0][i] = d[1][i - 1] + a[0][i];
			d[1][i] = d[0][i - 1] + a[1][i];

			if(d[1][i] < d[0][i - 2] + a[1][i])
				d[1][i] = d[0][i - 2] + a[1][i];
			if(d[0][i] < d[1][i - 2] + a[0][i])
				d[0][i] = d[1][i - 2] + a[0][i];
		}
		cout << max(d[0][n], d[1][n]) << '\n';
	}
}

#include <cstdio>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define M (int)1e5
int d[2][M + 1], t, n;
int main() {
	scanf("%d", &t); while(t--) {
		scanf("%d", &n); REP(i, 2) REP(j, n) scanf("%d", d[i] + j + 1);
		FOR(i, 1, n + 1) {
			d[0][i] = d[1][i - 1] + d[0][i] < d[0][i - 1] ? d[0][i - 1] : d[1][i - 1] + d[0][i];
			d[1][i] = d[0][i - 1] + d[1][i] < d[1][i - 1] ? d[1][i - 1] : d[0][i - 1] + d[1][i];
		}
		printf("%d\n", d[0][n] < d[1][n] ? d[1][n] : d[0][n]);
	}
}

//����
//Ǯ���� �ҽ��� ���غ��� ũ�� �ٸ����� �ʴ�. 
//�ٸ� �� ������ Ǯ�������� ���ذ� ���� �Ȱ��� -0-
//�ϴ� �̰� �ڷ����� Ǯ����.
//�ϴ� ���̽� ���̽���
//���� ��ġ�� �밢���� �������� ���Ѵ���
//�񱳱��� �����ؼ� �񱳸� ���ش�.
//P|P|O
//O|O|X
//�̷��� ���� �ִٸ�
//X + P[0] or X + P[1] �� �� ����̴�.