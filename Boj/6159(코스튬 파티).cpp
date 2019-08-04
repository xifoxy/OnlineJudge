#include <bits/stdc++.h>
using namespace std;
int d[1'000'001], n, costume, ans;
int main() {
	cin >> n >> costume;
	for(int i = 0; i < n; ++i)
		cin >> d[i];

	sort(d, d + n);
	int left = 0, right = n - 1;
	while(left != right) {
		if(d[right] + d[left] <= costume) {
			ans += (right - left);
			left++;
		} else right--;
	}
	cout << ans;
}

//#투 포인터

//정렬해서 주어진 크기보다 작거나 같은 합을 구하면 된다.