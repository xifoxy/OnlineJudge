#include <bits/stdc++.h>
using namespace std;
int n;
bool s[9];
void next_per(vector<int> &vec) {
	if(vec.size() == n) {
		for(auto &p : vec)
			cout << p << ' ';
		cout << '\n';
		return;
	}
	for(int i = 1; i <= n; ++i) {
		if(!s[i]) {
			s[i] = 1;
			vec.push_back(i);
			next_per(vec);
			vec.pop_back();
			s[i] = 0;
		}
	}
}
int main() {
	vector<int> v;
	cin >> n;
	next_per(v);
}

//N과 M 시리즈