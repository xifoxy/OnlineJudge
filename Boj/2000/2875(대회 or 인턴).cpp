#include <bits/stdc++.h>
using namespace std;
int w, m, k, team;
int main() {
	cin >> w >> m >> k;
	while(w > 1 && m > 0) {
		team++;
		w -= 2;
		m -= 1;
	}
	k -= (w + m);
	while(k > 0) {
		team--;
		k -= 3;
	}
	printf("%d\n", team);
}

//����
//������ �״��� ����� �ʴ�. ����� �ִ� �ִ����� ���� �����
//���� �ٿ����鼭 ������ ������ȴ�.