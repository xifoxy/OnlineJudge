#include <bits/stdc++.h>
using namespace std;
const int MX = 13;
int a[MX], n;
void sol(int pos, int sz, vector<int> &print) {
	if(print.size() == sz) {
		for(auto &p : print) {
			printf("%d ", p);
		}
		puts("");
		return;
	}

	for(int i = pos; i < n; ++i) {
		print.push_back(a[i]);
		sol(i + 1, sz, print);
		print.pop_back();
	}
}
int main() {
	while(scanf("%d", &n) && n != 0) {
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		vector<int> print;
		sol(0, 6, print);
		puts("");
	}
}

//»ý·«