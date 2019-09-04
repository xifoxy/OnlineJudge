#include <bits/stdc++.h>
using namespace std;
int tc;
int main(){
	scanf("%d", &tc);
	while(tc--){
		int n, a, sa = 0;
		double b, sb = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d %lf", &a, &b);
			sa += a;
			sb += (b * a);
		}
		printf("%d %.1f\n", sa, round(10 * sb / sa) / 10);
	}
}

// 말하지 않아도 알아요~