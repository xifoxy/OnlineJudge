#include <bits/stdc++.h>
using namespace std;
int d[2][6];
int N, K, sum;
int main() {
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; ++i) {
		int gender, grade;
		scanf("%d%d", &gender, &grade);
		d[gender][grade - 1]++;
	}

	for(int i = 0; i < 6; ++i) {
		if(d[0][i])
			sum += d[0][i] % K ? d[0][i] / K + 1 : d[0][i] / K;
		if(d[1][i])
			sum += d[1][i] % K ? d[1][i] / K + 1 : d[1][i] / K;
	}
	printf("%d\n", sum);
}

// 생략