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

// 설명(Stack)
// 레이저의 방향은 왼쪽이기 때문에 스택에 들어 있는 탑보다 작거나 큰 경우만 생각하면 된다.
// 스택에 있는 탑 보다 큰 탑이 나오게 되면 스택에 있는 작은 탑들은 무용지물이 되기 때문에 빼주고
// 스택의 탑 보다 작은게 나올때는 더 작은것이 나올걸 경우에 두면 된다.