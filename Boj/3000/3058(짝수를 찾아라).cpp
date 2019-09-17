#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int sum = 0, min_num = 999, num;
		for(int i = 0; i < 7; ++i){
			scanf("%d", &num);
			if(num % 2) continue;
			sum += num;
			min_num = min(min_num, num);
		}
		printf("%d %d\n", sum, min_num);
	}
}

// 말하지 않아도 알아요~