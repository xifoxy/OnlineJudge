#include <bits/stdc++.h>
using namespace std;
int n, a, zero, one, m_one;
long long ans;
int main() {
	vector<int> plus, minus;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a);
		if(a == 1) one++;
		else if(a == -1) m_one++;
		else if(a > 1) plus.push_back(a);
		else if(a < -1) minus.push_back(a);
		else zero++;
	}
	sort(plus.begin(), plus.end(), greater<int>());
	sort(minus.begin(), minus.end());

	for(int i = 0; i < plus.size(); i += 2) {
		if(i + 1 == plus.size()) ans += plus[i];
		else ans += (plus[i] * plus[i + 1]);
	}

	for(int i = 0; i < minus.size(); i += 2) {
		if(i + 1 == minus.size()) {
			if(m_one) {
				ans += (minus[i] * -1);
				m_one--;
			} else if(zero) zero--;
			else {
				ans += minus[i];
			}
		} else ans += (minus[i] * minus[i + 1]);
	}

	if(m_one > 1) {
		ans += (m_one / 2);
		m_one %= 2;
	}
	if(m_one && zero) {
		m_one = m_one <= zero ? 0 : m_one - zero;
	}
	printf("%lld", ans + (one - m_one));
}

//����
//���� Ž�彺���� Ǯ��ȴ�.
//��������� ū������
//���������� ����������
//��������
//
//���⼭ ���ܴ� - 1, 0, 1�� ������̴�.
//������ �����ϸ�
//4 * 1 = 4, 4 + 1 = 5
//-4 * -1 = 4, -4 * 0 = 0
//-1 * -1 = 1
//�̷��� �����鸸 ó�����ָ�ȴ�.