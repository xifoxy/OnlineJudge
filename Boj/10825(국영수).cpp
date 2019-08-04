#include <bits/stdc++.h>
using namespace std;
int n;
struct P {
	int kor, eng, math;
	string name;
};
P d[100001];
bool cmp(const struct P &u, const struct P &v) {
	if(u.kor == v.kor) {
		if(u.eng == v.eng) {
			if(u.math == v.math) {
				return u.name < v.name;
			}
			return u.math > v.math;
		}
		return u.eng < v.eng;
	}
	return u.kor > v.kor;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> d[i].name >> d[i].kor >> d[i].eng >> d[i].math;
	stable_sort(d, d + n, cmp);
	for(int i = 0; i < n; ++i)
		cout << d[i].name << '\n';
}

//설명
//문제설명만 잘 읽어보자
