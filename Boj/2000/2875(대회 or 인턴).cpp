#include <bits/stdc++.h>
using namespace std;
int w, m, k, team;
int main() {
	cin >> w >> m >> k;
	while(w > 1 && m > 0) {
		team++;
		w -= 2;
		m -= 1;
	}
	k -= (w + m);
	while(k > 0) {
		team--;
		k -= 3;
	}
	printf("%d\n", team);
}

//설명
//증명은 그다지 어렵지 않다. 만들수 있는 최대한의 팀을 만들고
//팀을 줄여가면서 인턴을 보내면된다.