#include <bits/stdc++.h>
using namespace std;
int n, w, h, d[100001];
int sol(stack<int> &st, int x) {
	int ret = 0;
	while(!st.empty() && d[st.top()] > d[x]) {
		h = st.top();
		st.pop();
		w = x;

		if(!st.empty())
			w -= st.top() + 1;
		ret = max(ret, w * d[h]);
	} 
	st.push(x);
	return ret;
}

int main() {
	stack<int> st;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", d + i);
		ans = max(ans, sol(st, i));
	}
	if(!st.empty())
		ans = max(ans, sol(st, n));
	printf("%d\n", ans);
}

// ����(Stack�� �̿��� Ǯ��)
// 1. ���̰� ����� ���� �迭 d�̴�.
// 2. stack���� ������׷��� �ε���(�ʺ�� �̿�ȴ�)�� ����ȴ�.
// 3. �ַ���� ũ�� 2���� ��츦 �����ؾ��Ѵ�.
// 3-1. ������ ���̺��� ū ���� ���ö�.
//  -�� ���� ���ÿ� �ε����� �������� ���� �ȴ�.
// 3-2. ������ ���̺��� ���� ���� ���ö�.
//	-���� ���� �ð��̴�. ������ �� ���� �غ���, ������ ������ ���� ���� ������ �Ǹ�
//	 ���ÿ��� ���Ѱ�� �̷�� ������׷��� ����Ǿ� �ֱ� ������ ������ ���� ������ ����ϸ� �ȴ�.
// 4. ���������� ������ ����ִ��� �ٽ��ѹ� �˻��ϸ� ����� ���ش�.