#include <bits/stdc++.h>
using namespace std;
int q, w, e, r;
int a, s, d, f;

int main(){
	cin >> q >> w >> e >> r;
	cin >> a >> s >> d >> f;
	cout << max(q + w + e + r, a + s + d + f);
}

// 말하지 않아도 알아요~