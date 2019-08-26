#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vec;

void f() {
	if(vec.size() == m) {
		for(auto &p : vec)
			printf("%d ", p);
		puts("");
		return;
	}

	for(int i = 1; i <= n; ++i) {
		vec.push_back(i);
		f();
		vec.pop_back();
	}
}

int main() {
	scanf("%d%d", &n, &m);
	f();
}