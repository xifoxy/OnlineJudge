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

// ����(Dictionary)
// ��ųʸ� ����ü�� ������� �ƴ°��� ���� �����̴�.
// �ΰ��� ����ü�� �̿��� ������ ����Ž��, ������ ���ڿ� Ž������ �����ϰԲ� ����� �ȴ�.