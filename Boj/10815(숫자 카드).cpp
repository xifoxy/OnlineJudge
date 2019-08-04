#include <bits/stdc++.h>
using namespace std;
int n, a;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	set<int> st;
	set<int>::iterator it;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		st.insert(a);
	}
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		it = st.find(a);
		if(it != st.end()) cout << 1;
		else cout << 0;
		cout << ' ';
	}
}

#include <bits/stdc++.h>
using namespace std;
int a[500001], n, m, num, l, r, mid;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	sort(a, a + n);
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d", &num);
		l = 0; r = n;
		bool ans = false;
		while(l <= r) {
			mid = (l + r) / 2;
			if(a[mid] > num) r = mid - 1;
			else if(a[mid] < num) l = mid + 1;

			if(a[mid] == num) {
				ans = true;
				break;
			}
		}
		printf("%d ", ans ? 1 : 0);
	}
}

//설명
//문제를 읽어보면 전형적인 이분탐색이다.
//솔루션은 두개인데 하나는 자료구조를 set으로 만든것이고,
//다른 하나는 입력이 들어올때마다 이분탐색을 하는것이다.
//솔루션 둘다 인풋값에 대해 정렬된다는것과, 구조형성에 있어서 시간복잡도도 유사하다고 볼 수 있다.
//확실히 stl을 쓰면 메모리를 많이 먹기는 한다.