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

// 설명(Sieve of Eratosthenes)
// 체를 이용해 소수를 걸러내고, 소수의 연속합이 N이 되는합들을 구하면 된다.