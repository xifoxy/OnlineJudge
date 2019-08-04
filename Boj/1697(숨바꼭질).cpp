#include <bits/stdc++.h>
using namespace std;
const int MX = 100001;
int a[MX], n, m;
int main() {
	scanf("%d%d", &n, &m);
	queue<int> Q;
	for(int i = 0; i < 100001; ++i) a[i] = MX;
	a[n] = 1, Q.push(n);

	if(n > m) printf("%d\n", n - m);
	else {
		while(!Q.empty()) {
			int pos = Q.front(); Q.pop();
			if(pos * 2 <= MX && a[pos * 2] > a[pos] + 1) {
				a[pos * 2] = a[pos] + 1;
				Q.push(pos * 2);
			}
			if(pos - 1 >= 0 && a[pos - 1] > a[pos] + 1) {
				a[pos - 1] = a[pos] + 1;
				Q.push(pos - 1);
			}
			if(pos + 1 <= MX && a[pos + 1] > a[pos] + 1) {
				a[pos + 1] = a[pos] + 1;
				Q.push(pos + 1);
			}
		}
		printf("%d\n", a[m] - 1);
	}
}

//설명
//단순 반복문으로 풀기 곤란한 문제이다. 약간 BFS에 가깝다고 해야하나?
//문제를 이해를 하고 있으면 쉬운 문제이다.
//구조체는 이전정보를 쉽게 꺼낼 수 있는 큐를 이용했고, 그 정보를 가지고
//다음 좌표의 값을 구하면 된다.
//단, 문제에서 N과 K의 관계가 N > K일때를 잘 생각해보자.