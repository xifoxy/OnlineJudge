#include <bits/stdc++.h>
using namespace std;
int n, a;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	set<int> st;
	while(n--) {
		cin >> a;
		st.insert(a);
	}
	cin >> n;
	while(n--) {
		cin >> a;
		if(st.find(a) != st.end())
			cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;
int d[100001], n, m, a;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> d[i];
	cin >> m;
	sort(d, d + n);
	while(m--) {
		int l = 0, r = n;
		cin >> a;
		bool ans = false;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(d[mid] == a) {
				ans = true;
				break;
			}
			if(d[mid] > a) {
				r = mid - 1;
			} else l = mid + 1;
		}
		cout << (ans ? 1 : 0) << '\n';
	}
}

// 설명(Binary Search)
// 이분탐색으로 풀 수 있는 문제이다.
// 단, 입력받고 정렬해야한다.
// 아니면 BST가 보장되는 자료구조를 이용하면된다.