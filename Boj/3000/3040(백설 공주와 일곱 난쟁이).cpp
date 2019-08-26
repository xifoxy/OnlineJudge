#include <bits/stdc++.h>
using namespace std;
int hei[10], sum;
int main(){
	for(int i = 0; i < 9; ++i){
		scanf("%d", &hei[i]);
		sum += hei[i];
	}

	sum -= 100;
	for(int i = 0; i < 9 && sum; ++i){
		for(int j = i + 1; j < 9; ++j){
			if(sum == hei[i] + hei[j]){
				hei[i] = hei[j] = sum = 0;
				break;
			}
		}
	}
	for(int i = 0; i < 9; ++i)
		if(hei[i])
			printf("%d\n", hei[i]);
}

// 설명(Brute force)
// 7개의 수가 100이 되는걸 찾는 문제
// 바꿔 말하면 9개의 합 - 100 되는 숫자 2개를 찾는 문제로 바뀌게 된다.
// 두개만 뽑으면 되니 간단하게 반복문으로 해결.