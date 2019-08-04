#include <bits/stdc++.h>
using namespace std;
int n, ans, l, r;
int main() {
	vector<int> vec;
	vec.reserve(500);
	for(int i = 1; i <= 500; ++i)
		vec.push_back(i * i);

	cin >> n;
	while(r < 500) {
		if(vec[r] - vec[l] >= n) {
			if(vec[r] - vec[l] == n) ++ans;
			++l;
		} else ++r;
	}
	cout << ans;
}

//#투 포인터

//완전 제곱수 구해놓고 인덱스 움직이면서 구하면 된다.