#include <bits/stdc++.h>
using namespace std;
const int MAX = 13e4;
vector<int> adj[MAX];
int animal[MAX], n;
long long sol(int cur) {
	long long ret = animal[cur];
	for(auto &p : adj[cur]) {
		ret += sol(p);
	}
	return ret < 0 ? 0 : ret;
}
int main() {
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i) {
		char t;
		int a, p;
		scanf(" %c %d%d", &t, &a, &p);
		animal[i] = a;
		if(t == 'W') animal[i] = -a;
		adj[p].push_back(i);
	}
	printf("%lld\n", sol(1));
}

//생략