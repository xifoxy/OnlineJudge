#include <bits/stdc++.h>
using namespace std;
int st, ed, num, ans;
bool d[6000001];
int main() {
	scanf("%d%d%d", &st, &ed, &num);

	for(int i = 2; i * i <= ed; ++i) {
		if(!d[i]) {
			for(int j = i *i; j <= ed; j += i)
				d[j] = true;
		}
	}
	d[0] = d[1] = true;
	for(int i = st; i <= ed; ++i) {
		if(!d[i]) {
			int t = i;
			while(t > 0) {
				if(t % 10 == num) {
					ans++;
					break;
				}
				t /= 10;
			}
		}
	}
	printf("%d\n", ans);
}

//#에라토스테네스의 체

//뭔 삽질을 했는지 모르겠지만 3번 틀렸다 --
//그냥 풀면된다, 못풀어서 손목 잘릴뻔했다.