#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, cnt;
ll idx = 4611686018427387904, a;
map<ll, int> mp;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		mp[a]++;
		if(cnt < mp[a]) {
			idx = a;
			cnt = mp[a];
		}
		if(idx != a && mp[a] == mp[idx])
			idx = min(a, idx);
	}
	cout << idx << '\n';
}

//����
//��������� ������ ���ؼ� 5���̳� Ʋ�ȴ�.
//�Է� ��ü�� 100���� �ۿ� �ȵ����� ������ ���� �������
//-idx <= N <= idx �̱⶧���� �ڷᱸ���� map���� �ϸ� �����ϴ�.
//���� ���� ���� �ߺ��Էµ� �� ������, ���� ���� �� �̴� ���ǹ� �ۼ��� ��������.