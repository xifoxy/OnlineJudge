#include <bits/stdc++.h>
using namespace std;
const int M = 1e2 + 1;
int board[M][M];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n, m;
struct info {
	int x, y;
};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
void flood_fill(int x, int y, queue<info> &ret) {
	queue<info> Q;
	Q.push({x,y});
	board[x][y] = -1;
	while(!Q.empty()) {
		info t = Q.front();
		Q.pop();

		for(int i = 0; i < 4; ++i) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if(safe(nx, ny) && (board[nx][ny] == 0 || board[nx][ny] > 0)) {
				if(board[nx][ny]) {
					board[nx][ny]++;
					if(board[nx][ny] == 3) ret.push({nx,ny});
				} else {
					board[nx][ny] = -1;
					Q.push({nx,ny});
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);

	queue<info> Q;
	flood_fill(0, 0, Q);
	

	int ans = 0;
	while(!Q.empty() && ++ans) {
		int sz = Q.size();
		for(int i = 0; i < sz; ++i) {
			info cur = Q.front();
			Q.pop();

			board[cur.x][cur.y] = -1;
			for(int k = 0; k < 4; ++k) {
				int nx = cur.x + dx[k];
				int ny = cur.y + dy[k];
				if(board[nx][ny] > 0) board[nx][ny]++;
				if(board[nx][ny] == 3) Q.push({nx,ny});
				if(board[nx][ny] == 0) {
					flood_fill(nx, ny, Q);
				}
			}
		}
	}
	printf("%d\n", ans);
}

#include <bits/stdc++.h>
using namespace std;
const int M = 1e2 + 1;
int board[M][M];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n, m;
struct info {
	int x, y;
};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

// �ʱ⿡ ġ��� ���Ⱑ ���� �κ� ó�� �� ���� ����� �ܺΰ��Ⱑ ���������� ���� �Լ�
void flood_fill(int x, int y, queue<info> &ret) {
	queue<info> Q;
	Q.push({x,y});
	board[x][y] = -1;
	while(!Q.empty()) {
		info t = Q.front();
		Q.pop();

		for(int i = 0; i < 4; ++i) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if(safe(nx, ny) && (board[nx][ny] == 0 || board[nx][ny] > 0)) {
				if(board[nx][ny]) {
					board[nx][ny]++;
					if(board[nx][ny] == 3) ret.push({nx,ny});
				} else {
					board[nx][ny] = -1;
					Q.push({nx,ny});
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);

	queue<info> Q;
    // �־��� input���� �׵θ��� ���δ� �����̴�.
	flood_fill(0, 0, Q);
	

    // �Ʒ����� ������ 3�� �� �ð��� üũ�ϱ� ���� ť�� ������� �ݺ��Ѵ�.
	int ans = 0;
	while(!Q.empty() && ++ans) {
		int sz = Q.size();
		for(int i = 0; i < sz; ++i) {
			info cur = Q.front();
			Q.pop();

			board[cur.x][cur.y] = -1;
			for(int k = 0; k < 4; ++k) {
				int nx = cur.x + dx[k];
				int ny = cur.y + dy[k];
				if(board[nx][ny] > 0) board[nx][ny]++;

                // ť�� �ߺ��ǰԱ� ���̴� ������ ��������� �Ѵ�.
				if(board[nx][ny] == 3) Q.push({nx,ny});

                // �ܺ� ����� �ܺ� ���Ⱑ �������� ȣ��
				if(board[nx][ny] == 0) {
					flood_fill(nx, ny, Q);
				}
			}
		}
	}
	printf("%d\n", ans);
}

// ����(BFS)
// �־��� ġ��� ����(0)�� ���� ������ 2�̻� �̸� �� ������ ��´�.
// ġ��ӿ� �� ������ �ܺ� ����� ���˵Ǳ� �������� ������ ������� �ʴ´�.
// �־��� ������ �׵θ��� ������ �����̴�.

// ���� ������ �������� �־��� �����ε�, ���⼭ ���� üũ Ž���� ġ�� ���� ��Ʈ��
// ���� ������ Ǯ����.

// 1. input���� �־����� ġ�� �ܰ��� ���⸦ ���δ� - 1�� ����� �ֵ� ġ��� ���� ������
// + 1 ���ش�.(flood_fill�Լ� ���� �Ͼ�� ��)

// ex) 
// 0 0 0 0		-1 -1 -1 -1
// 0 1 1 0 ==>  -1  3  3 -1
// 0 1 0 0 ==>  -1  4 -1 -1
// 0 0 0 0		-1 -1 -1 -1

// 2. �׷��� ��ƾ� �ϴ� ������ � ������� üũ ����� �ұ� ? ó������ 2���� ū ���
// �� ť�� �������µ� �ߺ��Ǵ� ��ǥ�� �ʹ� ���� ��������.�׷��� �ش� ��ǥ�� ���� 3��
// �ɶ����� ť�� ������.

// 3. ���� ���Ⱑ �ܺ� ����� ���� ���� ��� ó���� ������ұ�?
//     ����� ġ� ó���Ѵ� ť���� �̸� ����� �޾� ť�� ������ ������ �ݺ�����
//     ���� �ذ��� �ȴ�.
//     ù����(8, ó������ flood_fillȣ��) -> �ι�° ����(11) -> ����° ����(2)
// ex)
// 0 0 0 0 0 0 0 0 0	  -1 -1 -1 -1 -1 -1 -1 -1 -1	 -1 -1 -1 -1 -1 -1 -1 -1 -1  
// 0 0 0 0 0 0 0 0 0	  -1 -1 -1 -1 -1 -1 -1 -1 -1	 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 0 1 1 0 0 0 1 1 0	  -1 [3][3]-1 -1 -1 [3][3]-1	 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 0 1 0 1 1 1 0 1 0 ==>  -1  2  0  2  2  2  0  2 -1 ==> -1 [4]-1 [4] 2 [4]-1 [4]-1
// 0 1 0 0 1 0 0 1 0 ==>  -1  2  0  0  1  0  0  2 -1 ==> -1 [3]-1 -1 [3]-1 -1 [3]-1
// 0 1 0 1 1 1 0 1 0	  -1  2  0  2  2  2  0  2 -1	 -1 [4]-1 [4] 2 [4]-1 [4]-1
// 0 1 1 0 0 0 1 1 0	  -1 [3][3]-1 -1 -1 [3][3]-1	 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 0 0 0 0 0 0 0 0 0	  -1 -1 -1 -1 -1 -1 -1 -1 -1	 -1 -1 -1 -1 -1 -1 -1 -1 -1

// 	  -1 -1 -1 -1 -1 -1 -1 -1 -1
// 	  -1 -1 -1 -1 -1 -1 -1 -1 -1
// 	  -1 -1 -1 -1 -1 -1 -1 -1 -1
//==> -1 -1 -1 -1 [5]-1 -1 -1 -1
//==> -1 -1 -1 -1 -1 -1 -1 -1 -1
// 	  -1 -1 -1 -1 [5]-1 -1 -1 -1
// 	  -1 -1 -1 -1 -1 -1 -1 -1 -1
// 	  -1 -1 -1 -1 -1 -1 -1 -1 -1