#include <bits/stdc++.h>
using namespace std;
long long ans, n, i;

int main(){
	scanf("%lld", &n);
	for(int i = 1; i < n; ++i){
		ans += (n * i + i);
	}
	printf("%lld\n", ans);
}

// 설명(Math)
// 몫과 나머지가 같은 경우와 몫과 나머지가 같을수 있는 범위를 찾아야 하는 문제이다.
// 우선 몫과 나머지가 같은 경우는 N * i + i 가 몫과 나머지가 같은 경우가 된다.
// 5를 예로 들어보면
// 6 = 5 * 1 + 1
// 12 = 5 * 2 + 2
// 18 = 5 * 3 + 3
// 24 = 5 * 4 + 4
// 여기서 알수 있는건 범위는 1~N-1이라는 것이다.
// 5의 배수에서는 4보다 큰 나머지가 나올 수 없기 때문이다.