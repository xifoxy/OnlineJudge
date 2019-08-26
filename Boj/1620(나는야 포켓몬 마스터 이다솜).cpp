#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;

	string pocket;
	map<int, string> dic;
	map<string, int> dic2;
	for(int i = 1; i <= n; ++i) {
		cin >> pocket;
		dic[i] = pocket;
		dic2[pocket] = i;
	}

	for(int i = 0; i < m; ++i) {
		cin >> pocket;
		if(pocket[0] >= '0' && pocket[0] <= '9')
			cout << dic[stoi(pocket)] << '\n';
		else cout << dic2[pocket] << '\n';
	}
}

// 설명(Dictionary)
// 딕셔너리 구조체를 사용할줄 아는가에 대한 문제이다.
// 두개의 구조체를 이용해 한쪽은 정수탐색, 한쪽은 문자열 탐색으로 가능하게끔 만들며 된다.