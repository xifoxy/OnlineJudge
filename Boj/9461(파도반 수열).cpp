#include <bits/stdc++.h>
using namespace std;
long long d[101]{1,1,1};
int tc, n;
int main() {
	for(int i = 3; i <= 100; ++i)
		d[i] = d[i - 2] + d[i - 3];
	cin >> tc;
	while(tc--) {
		cin >> n;
		cout << d[n - 1] << '\n';
	}
}

//����
//�ٺ����� ������ Ÿ���� ������ �ʾ� �� Ʋ�ȴ�--
//��Ģ�� ã�ƺ����� ����
//ã���� ������ ��ã�Ƶ� �������.
//�Ʒ� ����Ʈ�� �����ϵ��� ����.
//https://oeis.org/A000931
