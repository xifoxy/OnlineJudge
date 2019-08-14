#include <bits/stdc++.h>
using namespace std;
struct info {
	char ch;
	int num;
};
vector<info> v(26);
vector<string> s;
int number[26];
int main() {
	string str;
	int n;

	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> str;
		s.push_back(str);
		int k = pow(10, str.size());
		for(int j = 0; j < str.size(); ++j) {
			v[str[j] - 'A'].ch = str[j];
			v[str[j] - 'A'].num += k;
			k /= 10;
		}
	}
	sort(v.begin(), v.end(), [](info &u, info &v) { return u.num > v.num; });

	for(int i = 0; i < 10; ++i) {
		number[v[i].ch - 'A'] = 9 - i;
	}

	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < s[i].size(); ++j) {
			s[i][j] = number[s[i][j] - 'A'] + '0';
		}
		ans += stoi(s[i]);
	}
	cout << ans;
}

// 설명
// 백트래킹으로 풀어도 되는데 내 기준에선 위 소스가 더 직관적이어서 저렇게 풀었다.
// 내가 푼 방식은 입력으로 들어온 문자열들의 각 자릿수를 더해서
// 내림차순으로 정렬한 후 알파벳에 숫자를 기입하는 방식이다.
// ex)
// ABCD
// BABB
// 라는 입력이 있다고 해보자.
// 첫번째 문자열의 각 자릿값들을 갱신하면
// A = 1000, B = 100, C = 10, D = 1 이다
// 두번째 문자열의 각 자리값들을 다시 더해주면
// B = 1100, A = 1100, B = 1110, B = 1111이 된다.
// 이 값들을 토대로 정렬하면
// B = 1111
// A = 1100
// C = 10
// D = 1
// 이걸 토대로 값을 갱신해주면 된다.