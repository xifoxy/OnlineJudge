#include <bits/stdc++.h>
using namespace std;
const int MX = 2000001;
int arr[MX], n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n + m; ++i)
		scanf("%d", &arr[i]);

	int left = 0, right = n;
	while(left < n && right < m + n) {
		printf("%d ", arr[left] < arr[right] ? arr[left++] : arr[right++]);
	}
	while(left < n)
		printf("%d ", arr[left++]);
	while(right < m + n)
		printf("%d ", arr[right++]);
}

//����
//���ĵ� �迭�̱⿡ ���������� ���Һΰ� �ƴ� ���պκ��� �����ϸ�ȴ�.
//���� ������ �Ϸ��� fastio�� ����.