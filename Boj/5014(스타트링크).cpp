#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 1;
int a[MX], f, s, g, u, d;
int main() {
	cin >> f >> s >> g >> u >> d;
	a[s] = 1;

	queue<int> Q; Q.push(s);
	while(!Q.empty()) {
		int pos = Q.front(); Q.pop();
		if(pos + u <= f && (!a[pos + u] || a[pos] + 1 < a[pos + u])) {
			a[pos + u] = a[pos] + 1;
			Q.push(pos + u);
		}
		if(pos - d >= 1 && (!a[pos - d] || a[pos] + 1 < a[pos - d])) {
			a[pos - d] = a[pos] + 1;
			Q.push(pos - d);
		}
	}
	if(!a[g]) cout << "use the stairs";
	else cout << a[g] - 1;
}

//설명
//숨바꼭질이랑 유사하다.