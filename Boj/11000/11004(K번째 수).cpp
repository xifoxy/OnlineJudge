#include <bits/stdc++.h>
using namespace std;
int d[5000001];
int n, k;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> d[i];

	sort(d, d + n);
	cout << d[k - 1] << '\n';
}

//설명
//더러운 fastio이거 구현하면 속도는 빠르지만
//의미 없다고 생각한다.
//범위는 N개의 숫자를 입력받아 정렬했을때
//K번째 위치에 있는 수를 구하는것이다.
//1 <= N <= 5e6 이기때문에
//정렬에 NlogN을 하면 대략 5천만이 나온다.
//그냥 입력받고 정렬하고 출력하자.