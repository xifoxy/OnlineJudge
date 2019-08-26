#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		int d[3];
		cin >> d[0] >> d[1] >> d[2];
		sort(d, d + 3);
		printf("Scenario #%d:\n", i);
		if(1LL * d[0] * d[0] + d[1] * d[1] == d[2] * d[2])
			puts("yes\n");
		else puts("no\n");
	}
}

// 설명
// 고오오오급 수학