#include <bits/stdc++.h>
using namespace std;
#define M 0x7fffffff
int n, d[11], ans_min = M, ans_max = -M;
void next_per(vector<int> &oper, vector<int> &seq) {
	if(seq.size() == n - 1) {
		int s = d[0];
		for(int i = 1; i < n; ++i) {
			if(seq[i - 1] == 0) s += d[i];
			else if(seq[i - 1] == 1) s -= d[i];
			else if(seq[i - 1] == 2) s *= d[i];
			else s /= d[i];
		}
		ans_min = min(s, ans_min);
		ans_max = max(s, ans_max);
	}

	for(int i = 0; i < 4; ++i) {
		if(oper[i]) {
			oper[i]--;
			seq.push_back(i);
			next_per(oper, seq);
			oper[i]++;
			seq.pop_back();
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &d[i]);
	vector<int> oper(4), seq;
	for(int i = 0; i < 4; ++i)
		scanf("%d", &oper[i]);

	next_per(oper, seq);
	printf("%d\n%d\n", ans_max, ans_min);
}

//설명
//기존의 사칙연산과 다르게 우선순위가 좌측이 최우선이다.
//N과 M을 풀어봤으면 구현은 쉽게 떠올릴 수 있다.