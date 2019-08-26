#include <bits/stdc++.h>
using namespace std;
long long s, e;
int main() {
	cin >> s >> e;
	if(s > e) swap(s, e);
	cout << (e - s ? e - s - 1 : 0) << '\n';
	for(long long i = s + 1; i < e; ++i)
		cout << i << ' ';
}

// 이게 왜 20프로지?