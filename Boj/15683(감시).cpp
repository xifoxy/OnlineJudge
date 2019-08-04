#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y, dir, num;
};
int n, m, d[8][8], cctv;
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
int dp[8][8];
int dx2[]{-1,1,1,-1}, dy2[]{1,1,-1,-1};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int getsum() {
	int ret = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(!dp[i][j])
				ret++;
	return ret;
}
void func(P &r) {
	int nx = r.x;
	int ny = r.y;
	dp[nx][ny] = -1;
	while(1) {
		nx += dx[r.dir];
		ny += dy[r.dir];
		if(!safe(nx, ny) || d[nx][ny] == 6) break;
		dp[nx][ny] = -1;
	}
}
int flood(vector<P> vec) {
	memcpy(dp, d, sizeof(d));
	for(int i = 0; i < vec.size(); ++i) {
		P &r = vec[i];
		int nx = r.x;
		int ny = r.y;
		if(r.num == 1) func(r);
		else if(r.num == 2) {
			if(r.dir == 0) func(r), r.dir = 1, func(r);
			else r.dir = 2, func(r), r.dir = 3, func(r);
		} else if(r.num == 3) {
			if(r.dir == 0) r.dir = 1, func(r), r.dir = 2, func(r);
			else if(r.dir == 1) r.dir = 0, func(r), r.dir = 2, func(r);
			else if(r.dir == 2) r.dir = 0, func(r), r.dir = 3, func(r);
			else r.dir = 1, func(r), r.dir = 3, func(r);
		} else if(r.num == 4) {
			int direc = r.dir;
			for(int i = 0; i < 4; ++i) if(direc != i) {
				r.dir = i;
				func(r);
			}
		} else {
			for(int i = 0; i < 4; ++i) {
				r.dir = i;
				func(r);
			}
		}
	}
	return getsum();
}
int dfs(vector<P> &vec, int pos, int ctv) {
	int ret = 0xff;
	if(ctv == 0)
		return flood(vec);
	for(int i = pos; i < vec.size(); ++i) {
		if(vec[i].num == 5)
			ret = min(ret, dfs(vec, i + 1, ctv - 1));
		else for(int j = 0; j < 4; ++j) {
			if(vec[i].num == 2 && j > 1) break;
			int t = vec[i].dir;
			vec[i].dir = j;
			ret = min(ret, dfs(vec, i + 1, ctv - 1));
			vec[i].dir = t;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	vector<P> vec;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &d[i][j]);
			if(d[i][j] >= 1 && d[i][j] <= 5)
				vec.push_back({i,j,0,d[i][j]}), cctv++;
		}
	}
	printf("%d\n", dfs(vec, 0, cctv));
}

#include <bits/stdc++.h>
using namespace std;
int n, m, nx, ny, cnt, direction;
int d[8][8], detec[]{0,1,2,2,4,4};
int dx[]{0,-1,0,1}, dy[]{1,0,-1,0};

//CCTV���������� ���� �迭
//4�� CCTV���� ���� �������� �־��� �ش� ���⸸ �����ϸ� �ȴ�.
int dir[3][8]{
	{0,1,2,3},			//1��
	{0,2,1,3},			//2��
	{0,1,1,2,2,3,0,3}	//3��
};
struct P {
	int x, y, ctv, detec_size, dir;
};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && d[x][y] != 6;
}
int get(vector<P> &v) {
	int temp[8][8], ret = 0;
	memcpy(temp, d, sizeof(d));
	for(int i = 0; i < v.size(); ++i) {
		for(int j = 0; j < v[i].detec_size; ++j) {
			//4�� CCTV ��������
			if(v[i].ctv == 4 && j == v[i].dir) continue;

			//���������� �迭�� �����Ѱ� �������� �����̴�.
			//�����ؾ� �ϴ� ���� * ���� + j�� ���ָ�
			//3�� CCTV ���� ���
			//2 * 0 + (j = 0~1)�̸� 0�� 1
			//2 * 1 + (j = 0~1)�̸� 2�� 3
			//������ 4�� 5 �׸��� 6�� 7�̴�
			//3���� ���ڰ� �� �ð�������� ���ٰ� �����ϰ� dir�迭�� �� �������ָ�ȴ�.
			direction = dir[v[i].ctv - 1][v[i].detec_size * v[i].dir + j];
			if(v[i].ctv > 3) direction = j;
			nx = v[i].x + dx[direction];
			ny = v[i].y + dy[direction];
			while(safe(nx, ny)) {
				if(temp[nx][ny] == 0) ret++;
				temp[nx][ny] = v[i].ctv;
				nx += dx[direction];
				ny += dy[direction];
			}
		}
	}
	return ret;
}
int n_per(int pos, int depth, vector<P> &v) {
	if(!depth) return get(v);
	int ret = 0;
	for(int i = pos; i < v.size(); ++i) {
		for(int j = 0; j < 4; ++j) {
			//4��Ž���� �������� ������ ����µ�,
			//2�� CCTV�� ������ �ΰ� �ۿ� �������� �ʱ�빮�� ���� ó���� ���ش�.
			//������ 5�� CCTV�� ���� ó���� ����� �ϳ� �����Ƽ� �н�
			if(v[i].ctv == 2 && j > 1) break;
			int dir = v[i].dir;
			v[i].dir = j;
			ret = max(ret, n_per(i + 1, depth - 1, v));
			if(v[i].ctv == 5) break;
			v[i].dir = dir;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	vector<P> v;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &d[i][j]);
			//CCTV�� ��� �ش� ������ �����Ѵ�. 
			//detec�迭�� �ش� CCTV�� Ž���ؾ��ϴ� ������ �� �̴�.
			if(d[i][j] >= 1 && d[i][j] <= 5)
				v.push_back({i,j,d[i][j],detec[d[i][j]]});
			if(!d[i][j]) cnt++;
		}
	}
	printf("%d\n", cnt - n_per(0, v.size(), v));
}

//����
//�ҽ��� �ʹ� ������. �� ������ Ǯ�� �����ؾ� �� ��Ȳ��
//����ī�޶� ����ī�޶� �մ´ٴ� ���̴�.

//500����Ʈ�� ���� �ҽ��� �߰��ߴ�.(�ּ�����)
//�������� ������ ������ �ͼ������� �ʴ´�.. �ʹ� ���°�