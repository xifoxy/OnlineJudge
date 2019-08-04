#include <bits/stdc++.h>
using namespace std;
const int M = 1e3+2;
int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		char str[M], str2[M];
		int d[26] = {0,}, idx = 0, idx2 = 0;
		scanf("%s", str);
		for(idx = 0; str[idx]; ++idx)
			d[str[idx] - 'a']++;
		
		scanf("%s", str2);
		bool ans = true;
		for(idx2 = 0; str2[idx2]; ++idx2) {
			int cur = str2[idx2] - 'a';
			d[cur]--;
			if(d[cur] < 0) ans = false;
		}
		if(idx != idx2) ans = false;
		if(ans) puts("Possible");
		else puts("Impossible");
	}
}

// 설명
// O(N * (2*M)) 완탐으로 무난하게 체크하면된다.
// 1. 문자열의 길이가 같은지?
// 2. 카운팅된 문자가 다른지?