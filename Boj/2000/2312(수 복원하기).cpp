#include <bits/stdc++.h>
using namespace std;
int tc, n;
int main() {
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &n);
		int num = 2;
		while(n != 1) {
			int cnt = 0;
			while(!(n % num)) {
				n /= num;
				cnt++;
			}
			if(cnt) printf("%d %d\n", num, cnt);
			num++;
		}
	}
}

// ����(Math)
// ���μ������� ���� ����ϸ� �ȴ�.