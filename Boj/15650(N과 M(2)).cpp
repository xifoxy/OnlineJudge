#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vec;
void f(int pos) {
	if(vec.size() == m) {
		for(auto &p : vec)
			printf("%d ", p);
		puts("");
		return;
	}

	for(int i = pos; i <= n; ++i) {
		vec.push_back(i);
		f(i + 1);
		vec.pop_back();
	}
}
int main() {
	scanf("%d%d", &n, &m);
	f(1);
}