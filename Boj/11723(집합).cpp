#include <bits/stdc++.h>
using namespace std;
int d[21];
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		char cmd[7];
		int x;
		scanf("%s", cmd);
		if(cmd[1] == 'l' || cmd[0] == 'e')
			memset(d, (cmd[1] == 'l' ? true : false), sizeof(d));
		else scanf("%d", &x);
		if(cmd[0] == 'r') d[x] = false;
		else if(cmd[1] == 'd') d[x] = true;
		else if(cmd[0] == 'c') printf("%d\n", d[x] ? 1 : 0);
		else if(cmd[0] == 't') d[x] = d[x] ? false : true;
	}
}

// 설명
// 정답률이 왜 30프로 이하인지 이해가 안되는 문제다.
// scanf가 최대 600만개 들어오지만 시간이 1.5초 이기 때문에
// cin cout 을 그냥 쓰게 되면 터진다.
// 문자배열을 쓸때는 항상 '\n'가 들어올껄 생각하자.