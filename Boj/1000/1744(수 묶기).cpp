#include <bits/stdc++.h>
using namespace std;
int n, a, zero, one, m_one;
long long ans;
int main() {
	vector<int> plus, minus;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a);
		// 입력된 숫자들을 적절히 분배한다.
		if(a == 1) one++;
		else if(a == -1) m_one++;
		else if(a > 1) plus.push_back(a);
		else if(a < -1) minus.push_back(a);
		else zero++;
	}
	sort(plus.begin(), plus.end(), greater<int>());
	sort(minus.begin(), minus.end());

	// 1보다 큰 양수는 큰것끼리 곱해서 더한다.
	for(int i = 0; i < plus.size(); i += 2) {
		// 양수의 개수가 홀수일 경우
		if(i + 1 == plus.size()) ans += plus[i];
		// 짝수일 경우
		else ans += (plus[i] * plus[i + 1]);
	}

	for(int i = 0; i < minus.size(); i += 2) {
		// 홀수일 경우
		if(i + 1 == minus.size()) {
			// -1이 존재한다면 양수화 한다.
			if(m_one) {
				ans += (minus[i] * -1);
				m_one--;
			} else if(zero) zero--;
			// 양수화가 불가능하면 0으로 만든다.
			else ans += minus[i];
			// 둘다 불가능하면 그냥 더한다.
		} else ans += (minus[i] * minus[i + 1]);
		// 짝수일 경우
	}

	// -1개수가 2개 이상이면 양수화 해서 더한다.
	if(m_one > 1) {
		ans += (m_one / 2);
		m_one %= 2;
	}
	// -1이 아직도 남아 있고, 0이 아직도 남아 있다면 0으로 만든다.
	if(m_one && zero) m_one = m_one <= zero ? 0 : m_one - zero;

	// 다 더한다
	printf("%lld", ans + (one - m_one));
}

// 설명
// 수를 적절히 묶고(곱하고) 더하여 최대값으로 만들어야 하는데 
// 범위가 정수이기 때문에 예외처리가 좀 필요하다.