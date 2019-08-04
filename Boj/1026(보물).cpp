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

//배열 b를 정렬하지 말라고 하는데 이 문제는 결과론이 위주이기에 
//그냥 정렬해서 계산하면된다.