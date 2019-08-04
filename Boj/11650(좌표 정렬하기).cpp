#include <bits/stdc++.h>
using namespace std;
int n;
struct P {
	int x, y;
};
P d[100001];
bool cmp(const struct P &u, const struct P &v) {
	if(u.x == v.x) return u.y < v.y;
	return u.x < v.x;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> d[i].x >> d[i].y;

	stable_sort(d, d + n, cmp);
	for(int i = 0; i < n; ++i)
		cout << d[i].x << ' ' << d[i].y << '\n';
}

//설명
//소트 옵션을 하나 추가 해야된다.
//값이 하나가 아닌 여러개라면 퀵소트보다 안정정렬을 하는걸 추천한다.