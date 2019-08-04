#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	scanf("%d", &x);

	int y_basic, y_liter, y_charge;
	scanf("%d%d%d", &y_basic, &y_liter, &y_charge);

	int use;
	scanf("%d", &use);

	int ans = x * use;

	if(use >= y_liter){
		ans = min(ans, y_basic + (use - y_liter) * y_charge);
	} else ans = min(ans, y_basic);
	printf("%d\n", ans);
}

// 생략