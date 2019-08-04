#include <bits/stdc++.h>
using namespace std;
vector<int> v, temp;
int n, a;
int sol(vector<int> &vec, int pos = 0) {
	if(vec.size() == 3) {
		int s1 = 1, s2 = 1, s3 = 1, s4 = 1;
		for(int i = 0; i < n; ++i) {
			if(i <= vec[0]) s1 *= v[i];
			else if(i <= vec[1]) s2 *= v[i];
			else if(i <= vec[2]) s3 *= v[i];
			else s4 *= v[i];
		}
		return s1 + s2 + s3 + s4;
	}
	int ret = 0;
	for(int i = pos; i < n - 1; ++i) {
		vec.push_back(i);
		ret = max(ret, sol(vec, i + 1));
		vec.pop_back();
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a);
		v.push_back(a);
	}
	int ans = sol(temp);
	printf("%d\n", ans);
}

//처음에 너무 어렵게 구현하려고 해서 코드가 좀 많이 꼬였다.
//단순하게 접근 가능한 방법이 있더라.
//분할되는 구역을 4개 다 구하려고 하지말고 3개만 구하면
//남는부분이 4번째 구역이 된다.