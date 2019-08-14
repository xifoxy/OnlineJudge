#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	vector<int> vec;
	vec.reserve(n + 1);
	for(int i = 0; i < n; ++i) vec.push_back(i + 1);
	
	int pos;
	printf("<%d", vec[pos = k - 1]);
	while(vec.size() > 1) {
		vec.erase(vec.begin() + pos);
		pos = (pos + k - 1) % vec.size();
		printf(", %d", vec[pos]);
	}
	puts(">");
}

// 설명
// 조세퍼스 문제 보다 Input데이터의 범위가 커져서 원형 리스트의 구조를 이용할시 넣고 빼는 연산
// 이 많아서 시간초과가 생긴다. Naive하게 풀려면 벡터를 이용하면 된다.