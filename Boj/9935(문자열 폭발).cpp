#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
char ans[MAX], str[MAX], c4[44];
int main() {
	scanf("%s %s", &str, &c4);
	int c4size = strlen(c4);
	int strsize = strlen(str);

	int pos = 0;
	for(int i = 0; i < strsize; ++i) {
		ans[pos++] = str[i];
		if(pos - c4size >= 0 && ans[pos - 1] == c4[c4size - 1]) {
			int n = pos - c4size;
			bool chk = true;
			for(int j = n; j < n + c4size; ++j) {
				if(ans[j] != c4[j - n])
					chk = false;
			}
			if(chk) pos -= c4size;
		}
	}
	ans[pos] = '\0';
	printf("%s\n", !pos ? "FRULA" : ans);
}

//����
//��Ʈ��Ŭ������ �̿��� Ǯ���� �ߴµ�...
//������� ������ '\0'�� ���� �ʴ´�.

//���ߵ� ���ڿ��� ���̰� 36�̶� ���� ª�� ������
//���� ���ڿ��� ������ ���� ���ؼ� �ε��� �����ϸ� �ȴ�.