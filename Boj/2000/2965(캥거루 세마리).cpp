#include <bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main(){
	cin >> a >> b >> c;
	while(b - a - 1 || c - b - 1){
		ans++;
		if(b - a - 1 > c - b - 1){
			c = a + 1;
			swap(b,c);
		} else{
			a = b + 1;
			swap(b,a);
		}
	}
	printf("%d\n", ans);
}

// 설명
// 쉽다. 두캥거루 사이의 공간이 더 큰곳에 이동하되,
// 이동후 공간을 최대로 하기 위해 두 캥거루중 아무거나 가장 가까운 위치로
// 옮기면 해결된다.