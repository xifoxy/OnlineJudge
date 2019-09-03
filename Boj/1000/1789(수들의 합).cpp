#include <bits/stdc++.h>
using namespace std;
long long a, sum;
int i;
int main(){
	scanf("%lld", &a);
	for(;;++i){
		sum += i;
		if(sum > a) break;
	}
	printf("%d\n", i - 1);
}

// 설명
// 문제 설명이 거지같지만, 그냥 공차가 1 인 등차수열의 합이
// 주어진 N 작거나 같은 범위 내에서 A[i] 를 구하는 문제이다.