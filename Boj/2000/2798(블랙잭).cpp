#include <bits/stdc++.h>
using namespace std;
int Card[101];
int main(){
	int n, m, sum = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d", &Card[i]);
	}

	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			for(int k = j + 1; k < n; ++k){
				int sum_C = Card[i] + Card[j] + Card[k];
				if(sum_C <= m){
					sum = max(sum, sum_C);
				}
			}
		}
	}
	printf("%d\n", sum);
}

// ����(Brute Force)
// ī�� 3���� ���� <= M�� �Ǵ� �ִ밪�� ���ϸ� �ȴ�.
// �־��� ī�� ���� N�� <= 100 �̱� ������ ��Ž���� �ذ� �����ϴ�.