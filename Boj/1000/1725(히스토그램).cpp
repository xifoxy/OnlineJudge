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
	REP(i, n) {
		scanf("%d", d + i);
		ans = max(ans, sol(st, i));
	}
	if(!st.empty())
		ans = max(ans, sol(st, n));
	printf("%d\n", ans);
}

//설명(스택을 이용한 풀이)
//1. 높이가 저장될 곳은 배열 d이다.
//2. stack에는 히스토그램의 인덱스(너비로 이용된다)가 저장된다.
//3. 솔루션은 크게 2개의 경우를 생각해야한다.
//3-1. 앞전의 높이보다 큰 값이 들어올때.
//	-이 경우는 스택에 인덱스를 누적시켜 가면 된다.
//3-2. 앞전의 높이보다 작은 값이 들어올때.
//	-값이 계산될 시간이다. 곰곰히 잘 생각 해보면, 앞전의 값보다 작은 값이 들어오게 되면
//	 스택에는 상한곡선을 이루는 히스토그램만 저장되어 있기 때문에 스택의 값을 빼가며 계산하면 된다.
//4. 마지막으로 스택이 비어있는지 다시한번 검사하며 계산을 해준다.
