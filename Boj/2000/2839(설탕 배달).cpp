#include <bits/stdc++.h>
int sugar(int f, int t, int nm) {
	if(nm < 0 || f < 0) return -1;
	if(nm % 3 == 0) {
		t += nm / 3;
		return f + t;
	} else
		return sugar(f - 1, t, nm + 5);
}

int main() {
	int n;
	scanf("%d", &n);
	int f, t = 0, nm;
	f = n / 5;
	nm = n % 5;
	
	printf("%d\n", sugar(f, t, nm));
	return 0;
}

// 설명
// 작은 아이디어 하나가 필요하다. 설탕 봉지를 최소화 하려면 당연히 5Kg 봉지가 더 많아야 한다.
// 주어진 무게를 전부 5Kg 봉지를 하나씩 빼가면서 무게를 완성하면 된다.