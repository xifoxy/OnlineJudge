#include <bits/stdc++.h>
using namespace std;
int cx[9], cy[9], cz[9];
int sudoku[10][10];
struct P{
    int x, y, z;
};
vector<P> v;
void dfs(int cur){
    // 0�� ��ǥ�� �Է��ص� ��� ���� ���� ����
    // ����ϰ� �����Ѵ�.
    if(cur == v.size()){
        for(int x = 0; x < 9; ++x){
            for(int y = 0; y < 9; ++y)
                printf("%d ", sudoku[x][y]);
            puts("");
        }
        exit(0);
    }
    P pos = v[cur];
    for(int num = 1; num <= 9; ++num){
        int bt = 1 << num;

        // �ּ����� ������ ���ǿ� ����, �ش� ���ڰ� �Ѱ��̶� �����ϸ� ���
        if(cx[pos.x] & bt || cy[pos.y] & bt || cz[pos.z] & bt) continue;

        // ��Ʈ�� ���ְ� ��͸� �Ѵ�.
        sudoku[pos.x][pos.y] = num;
        cx[pos.x] |= bt;
        cy[pos.y] |= bt;
        cz[pos.z] |= bt;

        dfs(cur + 1);

        // �� ���ڰ� ���� �ʴٸ� ���� �Ǳ⶧����
        // �ش� ���ڸ� �ٽ� ���ش�
        cx[pos.x] &= ~bt;
        cy[pos.y] &= ~bt;
        cz[pos.z] &= ~bt;
    }
}
int main(){
    int zero_cnt = 0;
    for(int x = 0; x < 9; ++x){
        for(int y = 0; y < 9; ++y){
            scanf("%d", sudoku[x] + y);
            // 3*3���� ĭ�� ���� �ε���
            int z_idx = x / 3 * 3 + y / 3;

            // OR������ �̿��� �Էµ� ������ġ�� ��Ʈ�� ���ش�
            cx[x] |= (1 << sudoku[x][y]);
            cy[y] |= (1 << sudoku[x][y]);
            cz[z_idx] |= (1 << sudoku[x][y]);
            if(sudoku[x][y] == 0){
                // �ߺ��Ǵ� �˻������ �����ϱ� ���� 0�� ��ġ�� �����Ѵ�.
                zero_cnt++;
                v.push_back({x, y, z_idx});
            }
        }
    }
    dfs(0);
}

// ����(DFS)
// �������� ������ 4������ �ִ�.

// 1. 9*9�� �������� 1~9������ ���ڸ� �����Ѵ�.
// 2. X���� ���ڵ��� �����ؾ� �Ѵ�.
// 3. Y���� ���ڵ��� �����ؾ� �Ѵ�.
// 4. 9*9�� ���Ӻ��带 9����(3*3)�������� ���ڴ� �����ؾ� �Ѵ�.

// X��� Y���� �����Ⱑ ����. �嵥, 3*3�� �������� ������ ������ ���� �ɷ¼Ҹ� �ߴ�.
// �׷���? ��� ������ ������.

// ������ ���� ������ ���ϱ� ���� ������� ó���� �ش��࿡ ����Ʈ�� ������� ������,
// �ʹ� ��ȿ������ ����ΰͰ��� ��Ʈ�������� �ذ��ߴ�.