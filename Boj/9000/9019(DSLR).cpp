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
    // 기저단위
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

        // 기저단위
		visit[a] = 1;
		queue<int> Q;
		Q.push(a);

		while(1){
			int temp = Q.front();
			Q.pop();

            // 출력
			if(temp == b){
				print(visit[b]);
				puts("");
				break;
			}
			int n;
			
			n = D(temp);
            // DSLR을 통해 만든 숫자가 처음 만든 숫자이면 해당 인덱스를 저장한다.
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

// 설명(BFS)
// 원래는 visit배열을 bool형식으로 만들고 큐에다가 구조체(string, int)를 집어넣었다.
// 그랬더니 통과는 되는데 시간이 폭발한다...
// 그래서 long long 배열로 바꿔서 출력할 답의 인덱스를 저장하는 방법으로 풀었다.