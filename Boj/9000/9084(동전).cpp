#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 1;
int tc;
int main(){
	scanf("%d", &tc);
	while(tc--){
        // ��������
		int dp[M]{1,}, coin[M]{0,};
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &coin[i]);
		}

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < M; ++j){
                // J���� ����� ���ؼ� J - coin[i]�� ���� 0���� ũ�ų� ������ �����Ѵ�.
				if(j - coin[i] >= 0)
					dp[j] += dp[j - coin[i]];
			}
		}
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
}

// ����(DP)
// �־��� �������� ���� �� �ִ� ���� �������� ���� ����� �ȴ�.