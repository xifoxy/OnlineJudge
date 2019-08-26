#include <bits/stdc++.h>
using namespace std;
long long d[91];
int n;
int main() {
	d[1] = 1;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i)
		d[i] = d[i - 1] + d[i - 2];

	printf("%lld\n", d[n]);
}

//설명
//이전에 푼것임에도 불구하고 값이 int형을 벗어난다는걸 감안하지 못해 틀렸다.
//직접 그려봐도 알 수 있지만
//공식은 D[N] = D[N - 1] + D[N - 2] 이다