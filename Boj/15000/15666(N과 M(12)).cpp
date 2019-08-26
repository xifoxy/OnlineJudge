#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vec, num;
void f(int pos) {
	if(vec.size() == m) {
		for(auto &p : vec)
			printf("%d ", p);
		puts("");
		return;
	}
	for(int i = pos; i < num.size(); ++i) {
		vec.push_back(num[i]);
		f(i);
		vec.pop_back();
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
	vector<int>::iterator it;
	it = unique(num.begin(), num.end());
	num.erase(it, num.end());
	f(0);
}