#include <bits/stdc++.h>
using namespace std;
string str;
int alpha_cnt[10], sum;
int main(){
	cin >> str;
	for(int i = 0; i < str.size(); ++i){
		sum += str[i] - '0';
		alpha_cnt[str[i] - '0']++;
	}

	if(sum % 3 != 0 || !alpha_cnt[0]) cout << -1 << '\n';
	else {
		sort(str.begin(), str.end());
		reverse(str.begin(), str.end());
	}
}

// ����(Sort)
// 30�� ����� �Ǳ� ���� ������ ���� ������?
// ����� 3�� ����� 10�� ����� ������ ������ �ȴ�.
// �׷��ϱ� 0�� �ϳ��� �����ؾ� �ϰ�, 3�� ����� �Ƿ��� �� �ڸ������� �� ��������
// 3���� ���������� �Ѵ�.