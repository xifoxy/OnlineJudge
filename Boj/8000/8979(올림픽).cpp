#include <bits/stdc++.h>
using namespace std;
struct medal{
	int num, g, s, b, rking;;
};
medal rnk[1001];

bool cmp(const medal &u, const medal &v){
	if(u.g == v.g){
		return u.s != v.s ? u.s > v.s : u.b > v.b;
	}
	return u.g > v.g;
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);

	for(int i = 0; i < n; ++i){
		int idx;
		scanf("%d", &idx);
		rnk[i].num = idx;
		scanf("%d%d%d", &rnk[i].g, &rnk[i].s, &rnk[i].b);
	}

	sort(rnk, rnk + n, cmp);

	int ans = rnk[0].num;
	for(int i = 0; i < n; ++i){
		rnk[i].rking = i + 1;
		if(i == 0) continue;

		if(rnk[i].g == rnk[i - 1].g && rnk[i].s == rnk[i - 1].s && rnk[i].b == rnk[i - 1].b)
			rnk[i].rking = rnk[i - 1].rking;
		else rnk[i].rking = i + 1;

		if(rnk[i].num == k) ans = rnk[i].rking;
	}
	printf("%d\n", ans);
}

// 설명(Sort)
// 문제에 주어진 조건대로 정렬하면 된다.