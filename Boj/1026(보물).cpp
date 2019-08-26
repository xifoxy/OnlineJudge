#include <bits/stdc++.h>
using namespace std;
int a[50], b[50];
int n;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + n, greater<int>());
	int sum = 0;
	for(int i = 0; i < n; ++i)
		sum += a[i] * b[i];
	cout << sum;
}

// 설명(Sort)
// 문제에서는 배열 B를 재정렬 하지 말라고 한다..ㅋㅋ
// 그런데 그냥 정렬하면 된다.
// 두배열을 하나는 오름차순으로, 하나는 내림차순으로 정렬하고 구하면 된다.