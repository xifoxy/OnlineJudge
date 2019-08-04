#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vec, num;
vector<vector<int>> ans;
bool visit[11];
void f() {
	if(vec.size() == m) {
		ans.push_back(vec);
		return;
	}
	for(int i = 0; i < num.size(); ++i) {
		if(!visit[i]) {
			visit[i] = true;
			vec.push_back(num[i]);
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
	sort(ans.begin(), ans.end());
	vector<vector<int>>::iterator it;
	it = unique(ans.begin(), ans.end());
	ans.erase(it, ans.end());

	for(int i = 0; i < ans.size(); ++i) {
		for(auto &p : ans[i])
			printf("%d ", p);
		puts("");
	}
}