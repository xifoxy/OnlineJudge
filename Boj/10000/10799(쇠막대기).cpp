#include <bits/stdc++.h>
using namespace std;
int ans, st;
char str[100'001];
int main() {
	scanf("%s", str);
	for(int i = 0; str[i]; ++i) {
		if(str[i] == '(') st++;
		else {
			st--;
			if(str[i - 1] == '(') ans += st;
			else ans++;
		}
	}
	printf("%d\n", ans);
}

//����
//��� �׸��� ���̴´�� ���� �����ؼ� Ǯ�� �Ǵ� �����̴�.
//���� ��ȣ�� ���������� ���ÿ� ���� ������ȣ ���� - 1�� ��ŭ ���ϸ� �ȴ�.