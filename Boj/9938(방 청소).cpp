#include <bits/stdc++.h>
using namespace std;
const int M = 3e5 + 1;
int N, L;
int parent[M], visit[M];
int Find(int x) {
	if(parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
int main() {
	scanf("%d%d", &N, &L);
	for(int i = 1; i <= L; ++i)
		parent[i] = i;
	for(int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		a = Find(a);
		b = Find(b);

		if(a != b) parent[a] = b;

		if(!visit[a] || !visit[b]) {
			visit[a] ? visit[b] = true : visit[a] = true;
			puts("LADICA");
		} else puts("SMECE");
	}
}

// 설명(Union Find)
// 문제를 이해하는데 너무 오래 걸렸다(두 시간..? 걸린것 같다.)

// 간단하게 요약하자면, Ai 와 Bi 는 연결관계가 된다(트리의 구조를 뛰게 된다.)
// 문제에서 나오는 테스트 케이스를 예로 들자면.
// 정리해야할 술이 9개 버켓이 10개
// 2 4 6 8 10 
// 1 3 5 7 9
// 테이스 케이스 5개까지는 Ai가 비어 있으므로 순차적으로 들어간다. 그리고
// 술이 들어간 1,3,5,7,9의 부모들은 순서대로 2,4,6,8,10이 된다.

// Ps. 괄호는 채워진 공간

// 여섯번째 술부터는 트리의 구조가 바뀐다(Ai = 2, Bi = 3)
// Ai가 비었으므로 술이 들어간다. Ai와 Bi를 연결 해줘야 하는데
// 앞선 테스트케이스에서 Bi의 부모는 4로 갱신되어 있다.
// (1)→(2)→4   (5)→6   (7)→8   (9)→10
//     (3)↗

// 일곱번째(Ai = 1, Bi = 5)
// 조건에 따라서 Ai채워져 있으니 
// Ai가 가르키는 노드 4에 공간에 술이 들어가고 5가 가르키는 노드는 6이니
// 아래와 같다.
// (1)↘ 
// (2)→  (4)↘
// (3)↗  (5)→ 6    (7)→8   (9)→10

// 여덟번째(Ai = 8, Bi = 2)
// Ai가 비었으니 Ai에 술을 채우고, 2번 노드가 가르키는 부모가 6이니
// 8번 노드가 포함된 컴포넌트는 6번 부모 밑으로 귀속된다.
// 컴포넌트는 두개로 줄어든다.

// 아홉번째(Ai = 7, Bi = 9)
// Ai가 채워져 있으니 Ai가 가르키는 6번 노드에 술을 채우고 9번노드와 연결하면
// 10번 노드 아래에 모든 노드들이 귀속되게 된다.