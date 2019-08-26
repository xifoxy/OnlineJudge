#include <bits/stdc++.h>
using namespace std;
int n, m, ans, num;
int main() {
	set<int> myset;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &num);
		myset.insert(num);
	}

	ans = m + n;
	for(int i = 0; i < m; ++i) {
		scanf("%d", &num);
		if(myset.find(num) != myset.cend())
			ans -= 2;
	}

	printf("%d\n", ans);
}

// 설명
// 사실 이 문제는 Binary Search를 써도 되고 Priority Queue를 써도 된다.
// 그런데 구현하기 귀찮으니까 그냥 STL에서 제공하는 BST를 사용하자.
// 두 집합의 배열의 원소 갯수를 다 더한 값에서
// 중복되는 값이 존재한다면 2개씩 빼면 답이 된다.