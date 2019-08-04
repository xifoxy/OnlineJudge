#include <bits/stdc++.h>
using namespace std;
int a[8], n, ans;
bool visit[8];
vector<int> vec;
void next_per() {
	if(vec.size() == n) {
		int temp = 0;
		for(int i = 1; i < n; ++i) {
			temp += abs(vec[i - 1] - vec[i]);
		}
		ans = max(ans, temp);
		return;
	}
	for(int i = 0; i < n; ++i) {
		if(!visit[i]) {
			vec.push_back(a[i]);
			visit[i] = true;
			next_per();
			visit[i] = false;
			vec.pop_back();
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	next_per();
	printf("%d\n", ans);
}

//설명
//정해는 떠오르지 않는다.
//범위가 작아서 완탐으로 조합을 만들고 그걸 토대로 답을 구했다.