#include <bits/stdc++.h>
using namespace std;
struct P {
	int st, ed;
};
int n, s, e, ans;
int main() {
	scanf("%d", &n);
	vector<P> v(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &s, &e);
		v[i] = {s,e};
	}
	sort(v.begin(), v.end(), [](const P &u, const P &v) {
		return u.ed < v.ed || (u.ed == v.ed && u.st < v.st);
	});
	/*sort(v.begin(), v.end(), [](const P &u, const P &v) {
		if(u.ed == v.ed)
			return u.st < v.st;
		return u.ed < v.ed;
	});*/
	int start = -1;
	for(int i = 0; i < v.size(); ++i) {
		if(v[i].st >= start) {
			start = v[i].ed;
			ans++;
		}
	}
	printf("%d\n", ans);
}

//설명
//과거에 소트 오퍼레이터를 왜 저따구로 짰는지 내 스스로도 이해가 되지 않는다..
//증명을 간략하게 줄이면 빨리 끝나는 순서로 정렬해서 구하면 된다.
//데이터가 있으면 표로 그려보는게 가장 직관적이다.
//끝나는 시간이 같을때 시작시간이 작은순으로 정렬 해주는 이유는
//데이터 정렬이
//2 2
//1 2이런식으로 되어 있다면 한번밖에 이용하지 못한다.
