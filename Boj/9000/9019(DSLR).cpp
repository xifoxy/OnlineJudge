#include <bits/stdc++.h>
using namespace std;
const int M = 1e4;
// DSLR
int D(int n){ return (n * 2) % M; }
int S(int n){ return n - 1 < 0 ? 9999 : n - 1; }
int L(int n){ return n % 1000 * 10 + n / 1000; }
int R(int n){ return n % 10 * 1000 + n / 10; }
long long visit[M + 1];
char ans[5]{"DSLR"};
void print(long long n){
    // ��������
	if(n == 1) return;
	print(n / 10);
	printf("%c", ans[n % 10 - 1]);
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		memset(visit, 0, sizeof(visit));
		int a, b;
		scanf("%d%d", &a, &b);

        // ��������
		visit[a] = 1;
		queue<int> Q;
		Q.push(a);

		while(1){
			int temp = Q.front();
			Q.pop();

            // ���
			if(temp == b){
				print(visit[b]);
				puts("");
				break;
			}
			int n;
			
			n = D(temp);
            // DSLR�� ���� ���� ���ڰ� ó�� ���� �����̸� �ش� �ε����� �����Ѵ�.
			if(!visit[n]){
				visit[n] = visit[temp] * 10 + 1;
				Q.push(n);
			}
			n = S(temp);
			if(!visit[n]){
				visit[n] = visit[temp] * 10 + 2;
				Q.push(n);
			}
			n = L(temp);
			if(!visit[n]){
				visit[n] = visit[temp] * 10 + 3;
				Q.push(n);
			}
			n = R(temp);
			if(!visit[n]){
				visit[n] = visit[temp] * 10 + 4;
				Q.push(n);
			}
		}
	}
}

// ����(BFS)
// ������ visit�迭�� bool�������� ����� ť���ٰ� ����ü(string, int)�� ����־���.
// �׷����� ����� �Ǵµ� �ð��� �����Ѵ�...
// �׷��� long long �迭�� �ٲ㼭 ����� ���� �ε����� �����ϴ� ������� Ǯ����.