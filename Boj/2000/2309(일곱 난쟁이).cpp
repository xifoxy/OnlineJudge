#include <bits/stdc++.h>
using namespace std;
int d[9], sum;
int main() {
	for(int i = 0; i < 9; ++i)
		scanf("%d", &d[i]), sum += d[i];

	sort(d, d + 9);
	for(int i = 0; i < 9; ++i) {
		for(int j = i + 1; j < 9; ++j) {
			if(sum - (d[i] + d[j]) == 100) {
				for(int k = 0; k < 9; ++k) {
					if(k == i || k == j) continue;
					printf("%d\n", d[k]);
				}
				return 0;
			}
		}
	}
}

//����
//�־��� �����̴� �� 9���̰� �ϰ��������� ���� 100�̴�.
//2�� �������� 100�� �Ǵ� ���� �����ϸ� �ȴ�