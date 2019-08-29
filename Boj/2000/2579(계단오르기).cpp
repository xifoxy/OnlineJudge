#include <bits/stdc++.h>
using namespace std;
int n, a[301], d[301];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	d[1] = a[1];
	d[2] = d[1] + a[2];

	for(int i = 3; i <= n; ++i) {
		if(d[i] < d[i - 2] + a[i])
			d[i] = d[i - 2] + a[i];
		if(d[i] < d[i - 3] + a[i] + a[i - 1])
			d[i] = d[i - 3] + a[i] + a[i - 1];
	}
	cout << d[n] << '\n';
}

#include <bits/stdc++.h>
using namespace std;
int a[10001], n, d[10001];
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	d[1] = a[1]; d[2] = d[1] + a[2];

	for(int i = 3; i <= n; ++i) {
		d[i] = d[i - 1];
		if(d[i] < d[i - 2] + a[i])
			d[i] = d[i - 2] + a[i];
		if(d[i] < d[i - 3] + a[i] + a[i - 1])
			d[i] = d[i - 3] + a[i] + a[i - 1];
	}
	cout << d[n];
}

// 설명
// 위는 계단오르기, 아래는 포도주 시식 보는바와 같이 점화식은 같으나
// 베이스 설정이 조금 다르다. 
// 2중 포문 도입부에 들어가는 D[i] = D[i - 1]
// 그건 문제에서 설명하는 "마지막 계단을 반드시 밟아야 한다"
// 이게 핵심이다. 포도주 시식은 마지막잔을 먹지 않더라도 최대한 많이 먹으면 되지만
// 계단 오르기는 마지막 계단을 무조건 밟아야 한다는 전제조건이 필요하다.