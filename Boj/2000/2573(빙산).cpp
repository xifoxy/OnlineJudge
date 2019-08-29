#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
};
const int M = 3e2+1;
int land[M][M], temp[M][M];
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
int n, m;
bool visit[M][M];

// �������� Ȯ��
bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

// ����ũ�� ī����
int land_divide_check(P temp){
    queue<P> Q;
    Q.push(temp);
    int ret = 1;
    visit[temp.x][temp.y] = true;
    while(!Q.empty()){
        P currnet = Q.front();
        Q.pop();

        for(int direction = 0; direction < 4; ++direction){
            int nx = currnet.x + dx[direction];
            int ny = currnet.y + dy[direction];
            if(safe(nx,ny) && !visit[nx][ny] && land[nx][ny]){
                visit[nx][ny] = true;
                ret++;
                Q.push({nx,ny});
            }
        }
    }

    return ret;
}

int year;
int bfs(queue<P> &Q){
    while(!Q.empty()){
        // �ѻ���Ŭ �������� üũ �ؾ� �ϱ� ������
        // visit�迭�� �ʱ�ȭ ���ְ�, ���� ������ land�迭�� temp(prev)�迭�� �����Ѵ�.
        memset(visit, false, sizeof(visit));
        memcpy(temp, land, sizeof(land));

        // ������ ��ǥ �ϳ��� flood fill�� ����������, ť�� ũ��� �ٸ��ٸ� ������ ���� ���̴�.
        int sz = land_divide_check(Q.front());
        if(sz != Q.size()) break;

        for(int i = 0; i < sz; ++i){
            P currnet = Q.front();
            Q.pop();

            for(int direction = 0; direction < 4; ++direction){
                int nx = currnet.x + dx[direction];
                int ny = currnet.y + dy[direction];

                // temp�迭�� prev�迭�̴�. ���� ������ ������ �����ؾߵȴ�. ���� ����
                if(safe(nx,ny) && temp[nx][ny] == 0 && land[currnet.x][currnet.y]){
                    land[currnet.x][currnet.y]--;
                }
            }
            // ���������� Ž���ص� ������ ��������� �ٽ� ť�� ����
            if(land[currnet.x][currnet.y])
                Q.push(currnet);
        }
        year++;
    }

    // ť�� ����ִ� ���� ��ǥ�� ���ٸ�? ������ �� ��ұ⿡ 0�� ��ȯ�ϰ�
    // ť�� ������ ��� �ִٸ� ī������ �ð��� ��ȯ�Ѵ�.
    return Q.size() ? year : 0;
}

int main(){
    scanf("%d%d",&n,&m);

    queue<P> Q;
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            scanf("%d", &land[x][y]);
            temp[x][y] = land[x][y];
            if(land[x][y]){
                Q.push({x,y});
            }
        }
    }
    printf("%d\n", bfs(Q));
}

// ����(BFS, flood fill)
// ������ ��,��,��,��� �����Ѱ��� ���� �����Ѵٸ�? �����ϴ� ���� �� ��ŭ ������ ��´�.
// �������� �䱸�ϴ� ���� ������ ��� ��, ������ �� ���� �̻����� �������� üũ�ϴ°� �̴�.
// ������ �� ������ 0�� ����ؾ� �Ѵ�.

// �ΰ����� �۾��� �ʿ��ߴ�.
// 1. ������ ������ �ΰ� �̻����� ����������?
// 2. ���� ���̱�

// �켱 �ַ���� Ż�������� ������ �� ��´� or ������ ������ �̴�. �̱� ������
// ������ ������ �ʿ��ϱ⿡ ���� �Է¹����� �迭��(temp, land �迭�� 2���� ����?)�� �Է¹ް�, 
// ���� �ƴ� ������ ��ǥ�� queue�� �߰��Ѵ�.

// ó�� �Է°����� ������ �ΰ��� ���� �� �ִٴ°� ������ Ž�� ���������� ������ ���� ���θ� üũ�Ѵ�.
// flood fill�� �迭�� ũ���, ť�� ��� ������ ��ǥ���� ����� ������..
// ������ ������ �κе��� Ž���ذ��鼭 ������ �������ش�.
// �� ������ ���̴� �κп��� �迭�� �ΰ� �� ���� ������ �ִµ�,

// �迭�� �Ѱ��� �����ϰ� �Ǹ�,
// ex)
// 0 0 0 0     0 0 0 0
// 0 1 5 0 ==> 0 0 5 0
// 0 0 0 0     0 0 0 0
// ���� ���� ���°� �߻��� �� �ִ�. �׷��� prev�迭�� ���� �������� ������̴�.

// ������ ���϶���
// �־��� Input���� ũ�Ⱑ �ִ� 300*300�� ���� �۱� ������ ť�� �ְ� ���⸦ �ݺ��ߴ�.