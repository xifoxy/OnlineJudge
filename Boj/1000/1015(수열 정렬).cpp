#include <bits/stdc++.h>
using namespace std;
const int M = 1e3;
struct P{
	int num;
	int f_idx;
	int s_idx;
};
P arr[M];
bool cmp(const P &a, const P &b){
	return a.num == b.num ? a.f_idx < b.f_idx : a.num < b.num;
}
bool cmp2(const P &a, const P &b){
	return a.f_idx < b.f_idx;
}
int main(){
	int n; 
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &arr[i].num);
		arr[i].f_idx = i;
	}

	sort(arr, arr + n, cmp);
	for(int i = 0; i < n; ++i){
		arr[i].s_idx = i;
	}
	sort(arr, arr + n, cmp2);
	for(int i = 0; i < n; ++i){
		printf("%d ", arr[i].s_idx);
	}
}

// ����(Sort)
// ���� ������ �� ��������..
// �׷��ϱ�...
// �Է¹ް� ù��° �ε����ο� -> �Է� �������� ���� + �ι�° �ε��� �ο� ->
// ù��° �ε����� �������� ���� -> �ι�° �ε��� ����̴�.
// �����ؾ��Ұ� �Է����� ������ ���ڰ� ���� ��� ù��°�� �ο��� �ε��� ������ �����ؾ��Ѵ�.