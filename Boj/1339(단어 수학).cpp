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


// ����
// ��Ʈ��ŷ���� Ǯ� �Ǵµ� �� ���ؿ��� �� �ҽ��� �� �������̾ ������ Ǯ����.
// ���� Ǭ ����� �Է����� ���� ���ڿ����� �� �ڸ����� ���ؼ�
// ������������ ������ �� ���ĺ��� ���ڸ� �����ϴ� ����̴�.
// ex)
// ABCD
// BABB
// ��� �Է��� �ִٰ� �غ���.
// ù��° ���ڿ��� �� �ڸ������� �����ϸ�
// A = 1000, B = 100, C = 10, D = 1 �̴�
// �ι�° ���ڿ��� �� �ڸ������� �ٽ� �����ָ�
// B = 1100, A = 1100, B = 1110, B = 1111�� �ȴ�.
// �� ������ ���� �����ϸ�
// B = 1111
// A = 1100
// C = 10
// D = 1
// �̰� ���� ���� �������ָ� �ȴ�.