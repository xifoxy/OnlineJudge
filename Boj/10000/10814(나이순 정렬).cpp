#include <bits/stdc++.h>
using namespace std;
int n;
struct P {
	int age, idx;
	string name;
};
P d[100001];
bool cmp(const struct P &u, const struct P &v) {
	if(u.age == v.age) return u.idx < v.idx;
	return u.age < v.age;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> d[i].age >> d[i].name;
		d[i].idx = i;
	}
	stable_sort(d, d + n, cmp);
	for(int i = 0; i < n; ++i)
		cout << d[i].age << ' ' << d[i].name << '\n';
}

//»ý·«