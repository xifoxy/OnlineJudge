#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(1){
		scanf("%d", &n);
		if(n == -1) break;
		vector<int> vec;
		int sum = 0;
		for(int i = 1; i <= n / 2; ++i){
			if(n % i == 0){
				sum += i;
				vec.push_back(i);
			}
		}
		printf("%d", n);
		if(sum == n){
			printf(" = %d", vec[0]);
			int sz = vec.size();
			for(int i = 1; i < sz; ++i)
				printf(" + %d", vec[i]);
			puts("");
		} else puts(" is NOT perfect.");
	}
}

// 말하지 않아도 알아요~