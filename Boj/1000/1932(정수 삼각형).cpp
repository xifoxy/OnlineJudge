#include <bits/stdc++.h>
using namespace std;
int d[501][501], n, ans;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			cin >> d[i][j];
			if(i) {
				if(!j) d[i][j] += d[i - 1][j];
				else if(j == i) d[i][j] += d[i - 1][j - 1];
				else d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
			}
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans << '\n';
}

//��ư� ������ �ʿ䰡 ����.
//N�ٿ� �ִ� ������ �ε��� 0�� N-1�� ���� ���� ó���� �صε��� �ϸ� �ǰ�
//�������� �ٷ������Ͱ� �� �������� �������� �ִ밪�� �׾Ƴ�������ȴ�.