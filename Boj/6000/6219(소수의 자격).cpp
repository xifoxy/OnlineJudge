#include <bits/stdc++.h>
using namespace std;
int st, ed, num, ans;
bool d[6000001];
int main() {
	scanf("%d%d%d", &st, &ed, &num);

	for(int i = 2; i * i <= ed; ++i) {
		if(!d[i]) {
			for(int j = i *i; j <= ed; j += i)
				d[j] = true;
		}
	}
	d[0] = d[1] = true;
	for(int i = st; i <= ed; ++i) {
		if(!d[i]) {
			int t = i;
			while(t > 0) {
				if(t % 10 == num) {
					ans++;
					break;
				}
				t /= 10;
			}
		}
	}
	printf("%d\n", ans);
}

//#�����佺�׳׽��� ü

//�� ������ �ߴ��� �𸣰����� 3�� Ʋ�ȴ� --
//�׳� Ǯ��ȴ�, ��Ǯ� �ո� �߸����ߴ�.