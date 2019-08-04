#include <bits/stdc++.h>
using namespace std;
char pic[64][64];
int N;
bool isAll0(int x, int y, int sz) {
	for(int i = x; i < x + sz; i++) {
		for(int j = y; j < y + sz; j++) {
			if(pic[i][j] == '1')
				return false;
		}
	}
	return true;
}
bool isAll1(int x, int y, int sz) {
	for(int i = x; i < x + sz; i++) {
		for(int j = y; j < y + sz; j++) {
			if(pic[i][j] == '0')
				return false;
		}
	}
	return true;
}

string quadtree(int x, int y, int sz) {
	if(isAll0(x, y, sz))
		return "0";
	if(isAll1(x, y, sz))
		return "1";
	int m = sz / 2;
	return "(" + quadtree(x, y, m) + quadtree(x, y + m, m) + quadtree(x + m, y, m) + quadtree(x + m, y + m, m) + ")";
}
int main(void) {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%s", pic[i]);
	cout << quadtree(0, 0, N);
}

//����
//�켱 ������ ������ ����Ʈ���� ���� ���������Ϳ� �Ұ��ϴ�.
//������ ������ ���� �����ϰ��� ����Ʈ���� ���ش� ����.
//�켱 ���� �ҽ��� �������ֽ� ��ŷ���Բ� ������ �λ縦 �帰��.
//
//������ ���� ������ ����3�̶�°� �ٽ��̾��ٸ�
//����Ʈ���� 2�� �ٽ��̴�. �� ������ ��ƺ��߰ڴ�.