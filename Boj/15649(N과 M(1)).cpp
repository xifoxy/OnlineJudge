#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vec;
bool visit[11];
void f() {
	if(vec.size() == m) {
		for(auto &p : vec)
			printf("%d ", p);
		puts("");
		return;
	}

	for(int i = 1; i <= n; ++i) {
		if(!visit[i]) {
			vec.push_back(i);
			visit[i] = true;
			f();
			vec.pop_back();
			visit[i] = false;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	f();
}