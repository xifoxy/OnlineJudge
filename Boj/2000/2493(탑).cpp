#include <bits/stdc++.h>
using namespace std;
struct P {
	int num, idx;
};
int n, a;
int main() {
	stack<P> st;
	scanf("%d %d", &n, &a);
	st.push({a, 1}); printf("0 ");
	for(int i = 2; i <= n; ++i) {
		scanf("%d", &a);
		while(st.size() && st.top().num < a)
			st.pop();
		if(st.size() && st.top().num > a)
			printf("%d ", st.top().idx);
		else printf("0 ");
		st.push({a, i});
	}
}

// ����(Stack)
// �������� ������ �����̱� ������ ���ÿ� ��� �ִ� ž���� �۰ų� ū ��츸 �����ϸ� �ȴ�.
// ���ÿ� �ִ� ž ���� ū ž�� ������ �Ǹ� ���ÿ� �ִ� ���� ž���� ���������� �Ǳ� ������ ���ְ�
// ������ ž ���� ������ ���ö��� �� �������� ���ð� ��쿡 �θ� �ȴ�.