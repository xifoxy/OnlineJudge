#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vec, num;
bool visit[11];
void f() {
	if(vec.size() == m) {
		for(auto &p : vec)
			printf("%d ", p);
		puts("");
		return;
	}

	for(int i = 0; i < num.size(); ++i) {
		if(!visit[i]) {
			vec.push_back(num[i]);
			visit[i] = true;
			f();
			visit[i] = false;
			vec.pop_back();
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		num.push_back(a);
	}
	sort(num.begin(), num.end());
	f();
}