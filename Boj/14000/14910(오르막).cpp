#include <bits/stdc++.h>
using namespace std;
int aft, bef;
int main() {
	bool ans = true;
	scanf("%d", &bef);
	while(scanf("%d", &aft) != EOF) {
		if(aft < bef) ans = false;
		bef = aft;
	}
	if(ans) puts("Good");
	else puts("Bad");
}

// 설명
// EOF(End of File)개념이 필요하다. 그리고 비교해주면 끝.