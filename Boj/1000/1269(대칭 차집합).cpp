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

// ����
// ��� �� ������ Binary Search�� �ᵵ �ǰ� Priority Queue�� �ᵵ �ȴ�.
// �׷��� �����ϱ� �������ϱ� �׳� STL���� �����ϴ� BST�� �������.
// �� ������ �迭�� ���� ������ �� ���� ������
// �ߺ��Ǵ� ���� �����Ѵٸ� 2���� ���� ���� �ȴ�.