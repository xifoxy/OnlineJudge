#include <bits/stdc++.h>
int sugar(int f, int t, int nm) {
	if(nm < 0 || f < 0) return -1;
	if(nm % 3 == 0) {
		t += nm / 3;
		return f + t;
	} else
		return sugar(f - 1, t, nm + 5);
}

int main() {
	int n;
	scanf("%d", &n);
	int f, t = 0, nm;
	f = n / 5;
	nm = n % 5;
	
	printf("%d\n", sugar(f, t, nm));
	return 0;
}

// ����
// ���� ���̵�� �ϳ��� �ʿ��ϴ�. ���� ������ �ּ�ȭ �Ϸ��� �翬�� 5Kg ������ �� ���ƾ� �Ѵ�.
// �־��� ���Ը� ���� 5Kg ������ �ϳ��� �����鼭 ���Ը� �ϼ��ϸ� �ȴ�.