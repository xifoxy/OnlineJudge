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

//����
//������ �о�� �������� �̺�Ž���̴�.
//�ַ���� �ΰ��ε� �ϳ��� �ڷᱸ���� set���� ������̰�,
//�ٸ� �ϳ��� �Է��� ���ö����� �̺�Ž���� �ϴ°��̴�.
//�ַ�� �Ѵ� ��ǲ���� ���� ���ĵȴٴ°Ͱ�, ���������� �־ �ð����⵵�� �����ϴٰ� �� �� �ִ�.
//Ȯ���� stl�� ���� �޸𸮸� ���� �Ա�� �Ѵ�.