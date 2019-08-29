#include <bits/stdc++.h>
using namespace std;
struct Node{
    int x, y, breaker;
};
const int M = 1e3 + 1;
char board[M][M];
int dp[2][M][M];
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int n, m;

bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

int bfs(){
    queue<Node> Q;
    dp[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()){
        Node current = Q.front();
        Q.pop();
        if(current.x == n - 1 && current.y == m - 1) return dp[current.breaker][current.x][current.y];
        for(int direction = 0; direction < 4; ++direction){
            int nx = current.x + dx[direction];
            int ny = current.y + dy[direction];

            // ���� �μ� ���¸� üũ�ϱ����� ����
            int bk = current.breaker;

            if(safe(nx,ny)){

                // ��������
                // �ʺ� �켱 Ž�� Ư���� �ش� ��ǥ �湮 ���θ� üũ�ϸ� �Ǳ� ������
                // �ʱ� �迭�� ���¸� �������� �����ϰ�� 0���� ���д�.
                if(board[nx][ny] == '1' && bk == 0 && !dp[bk + 1][nx][ny]){
                    Q.push({nx,ny,bk + 1});
                    dp[bk + 1][nx][ny] = dp[bk][current.x][current.y] + 1;
                } else if(board[nx][ny] == '0' && !dp[bk][nx][ny]){
                    Q.push({nx,ny,bk});
                    dp[bk][nx][ny] = dp[bk][current.x][current.y] + 1;
                }
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d%d", &n, &m);

    // �ӵ��� ���̱� ���ؼ��� %1d���� ���ڿ��� �Է¹޾� �Ľ��ϴ°� ����.
    for(int i = 0; i < n; ++i)
        scanf("%s", board[i]);

    printf("%d\n", bfs());
}

// ����(BFS, DP)
// �� ã�� �����ε�, "���� �ϳ� �μ� �� �ִ�" ��� ���� ������ �ٴ´�.
// �׷��ٸ� �޸������̼��� Ȱ���Ҷ� ���� �ν�������, ���� �μ��� �ʾ����� �� ������ ��츦 ����
// �޸� �س����� �ִܰŸ��� ���� �� �ִ�.

// �� �����غ��� �ν��� �� �� �ִ� �ִܰŸ��� �ٸ����� �ʺ�켱 Ž���̶�� ���Ѵ���
// �����ذ� �ƴѰ� �ڿ����� �ɷ����� �Ǿ� �ִ�.