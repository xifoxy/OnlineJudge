#include <bits/stdc++.h>
using namespace std;
int n, a, zero, one, m_one;
long long ans;
int main() {
	vector<int> plus, minus;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a);
		// �Էµ� ���ڵ��� ������ �й��Ѵ�.
		if(a == 1) one++;
		else if(a == -1) m_one++;
		else if(a > 1) plus.push_back(a);
		else if(a < -1) minus.push_back(a);
		else zero++;
	}
	sort(plus.begin(), plus.end(), greater<int>());
	sort(minus.begin(), minus.end());

	// 1���� ū ����� ū�ͳ��� ���ؼ� ���Ѵ�.
	for(int i = 0; i < plus.size(); i += 2) {
		// ����� ������ Ȧ���� ���
		if(i + 1 == plus.size()) ans += plus[i];
		// ¦���� ���
		else ans += (plus[i] * plus[i + 1]);
	}

	for(int i = 0; i < minus.size(); i += 2) {
		// Ȧ���� ���
		if(i + 1 == minus.size()) {
			// -1�� �����Ѵٸ� ���ȭ �Ѵ�.
			if(m_one) {
				ans += (minus[i] * -1);
				m_one--;
			} else if(zero) zero--;
			// ���ȭ�� �Ұ����ϸ� 0���� �����.
			else ans += minus[i];
			// �Ѵ� �Ұ����ϸ� �׳� ���Ѵ�.
		} else ans += (minus[i] * minus[i + 1]);
		// ¦���� ���
	}

	// -1������ 2�� �̻��̸� ���ȭ �ؼ� ���Ѵ�.
	if(m_one > 1) {
		ans += (m_one / 2);
		m_one %= 2;
	}
	// -1�� ������ ���� �ְ�, 0�� ������ ���� �ִٸ� 0���� �����.
	if(m_one && zero) m_one = m_one <= zero ? 0 : m_one - zero;

	// �� ���Ѵ�
	printf("%lld", ans + (one - m_one));
}

// ����
// ���� ������ ����(���ϰ�) ���Ͽ� �ִ밪���� ������ �ϴµ� 
// ������ �����̱� ������ ����ó���� �� �ʿ��ϴ�.