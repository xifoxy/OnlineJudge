#include <bits/stdc++.h>
int alpha[26], mx;
int main() {
	char ch;
	while(scanf("%c", &ch) != EOF) {
		if(ch >= 'a' && ch <= 'z') {
			alpha[ch - 'a']++;
			mx = std::max(mx, alpha[ch - 'a']);
		}
	}

	for(int i = 0; i < 26; ++i)
		if(alpha[i] == mx)
			printf("%c", i + 'a');
}

// ����
// ���� ���̴� ��������� ���� ���� �ҽ��� �ƴϴ�.
// EOF�� �������� ���ϰ� �ޱ� ���ؼ� ������ �̿�������, ���ڿ��� �������� ���� �� �ִ�
// �׷��ϱ�, ���� �������� ���� �� �ִ� getline�� �ξ� �� ȿ�����ϼ� �ִ�.
// ���� ���� ������� ������ scanf�� �ִ� 5õ������ ȣ��Ǳ� �����̴�.