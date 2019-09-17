#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a, b, c, l = 0, r = 1e10;
	cin >> a >> b >> c;
	while(l < r){
		long long mid = (l + r) / 2;
        // 달팽이는 올라가고나서 잠잘때 미끌어진다.
		if(mid * a - (mid - 1) * b >= c){
			r = mid;
		} else l = mid + 1;
	}
	cout << l << '\n';
}

// 설명(Binary Search)
// 이분탐색을 이용하면 쉽게 풀리는 문제이다.
// 조건문을 잘 살펴보자.