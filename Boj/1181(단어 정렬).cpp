#include <bits/stdc++.h>
using namespace std;
vector<string> vec;
int n;
bool cmp(const string &u, const string &v) {
	if(u.size() == v.size()) return u < v;
	return u.size() < v.size();
}
int main() {
	cin >> n;
	vec.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> vec[i];

	sort(vec.begin(), vec.end(), cmp);
	for(int i = 0; i < vec.size(); ++i) {
		if(!i) cout << vec[i] << '\n';
		else if(vec[i - 1] != vec[i])
			cout << vec[i] << '\n';
	}
}

// 설명(Sort)
// 문제에서 주어진 조건대로 Operator 혹은 Comapere Function을 이용해서 정렬 해주면된다.