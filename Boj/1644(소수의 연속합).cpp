#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 4e6 + 1;
int a[MX], n;
int main() {
	cin >> n;
	vector<int> v;
	for(ll i = 2; i <= n; ++i) {
		if(!a[i]) {
			v.push_back(i);
			for(ll j = i * i; j <= n; j += i) {
				a[j] = 1;
			}
		}
	}

	memset(a, 0, sizeof(a));
	for(int i = 0; i < v.size(); ++i) {
		int sum = 0;
		if(a[i] > n) break;
		for(int j = i; j < v.size(); ++j) {
			sum += v[j];
			if(sum > n) break;
			a[sum]++;
		}
	}
	cout << a[n];
}

//설명
//에라토스테네스의 체를 이용해서 소수를 우선 구현한다. N이 400만이기때문에
//400만까지의 소수를 다 구하고 이중포문으로 소수의 구간합이 400만 >= sum이 되도록
//탐색해서 배열에 체크해주면 된다.