#include <bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main(){
	cin >> a >> b >> c;
	while(b - a - 1 || c - b - 1){
		ans++;
		if(b - a - 1 > c - b - 1){
			c = a + 1;
			swap(b,c);
		} else{
			a = b + 1;
			swap(b,a);
		}
	}
	printf("%d\n", ans);
}

// ����
// ����. ��Ļ�ŷ� ������ ������ �� ū���� �̵��ϵ�,
// �̵��� ������ �ִ�� �ϱ� ���� �� Ļ�ŷ��� �ƹ��ų� ���� ����� ��ġ��
// �ű�� �ذ�ȴ�.