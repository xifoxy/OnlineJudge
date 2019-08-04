#include <bits/stdc++.h>
using namespace std;
int d[9], sum;
int main() {
	for(int i = 0; i < 9; ++i)
		scanf("%d", &d[i]), sum += d[i];

	sort(d, d + 9);
	for(int i = 0; i < 9; ++i) {
		for(int j = i + 1; j < 9; ++j) {
			if(sum - (d[i] + d[j]) == 100) {
				for(int k = 0; k < 9; ++k) {
					if(k == i || k == j) continue;
					printf("%d\n", d[k]);
				}
				return 0;
			}
		}
	}
}

//설명
//주어진 난쟁이는 총 9명이고 일곱난쟁이의 합은 100이다.
//2중 포문으로 100이 되는 값을 필터하면 된다