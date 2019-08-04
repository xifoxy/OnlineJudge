#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e2 + 1, INF = 1e9;
int dist[MAX_V][MAX_V];
int dist2[MAX_V][MAX_V];
map<string, int> city;
int main() {
	fill(&dist[0][0], &dist[MAX_V - 1][MAX_V], INF);
	fill(&dist2[0][0], &dist2[MAX_V - 1][MAX_V], INF);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	string ccity;
	for(int i = 1; i <= n; ++i) {
		cin >> ccity;
		city[ccity] = i;
		dist[i][i] = dist2[i][i] = 0;
	}

	int tour;
	cin >> tour;
	vector<string> cos;
	for(int i = 0; i < tour; ++i) {
		cin >> ccity;
		cos.push_back(ccity);
	}
	
	int info, cost;
	cin >> info;
	string type, start, end;
	for(int i = 0; i < info; ++i) {
		cin >> type >> start >> end >> cost;
		int idxs = city[start];
		int idxe = city[end];
		if(type[1] == '-')
			dist[idxs][idxe] = dist[idxe][idxs] = min(dist[idxs][idxe], cost / 2);
		else if(type[0] == 'I' || type[0] == 'M') 
			dist[idxs][idxe] = dist[idxe][idxs] = 0;
		else dist[idxs][idxe] = dist[idxe][idxs] = min(dist[idxs][idxe], cost);
		dist2[idxs][idxe] = dist2[idxe][idxs] = min(dist2[idxs][idxe], cost);
	}

	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
			}
		}
	}

	int sum1 = m, sum2 = 0;
	for(int i = 1; i < tour; ++i) {
		int s = city[cos[i - 1]];
		int e = city[cos[i]];
		sum1 += dist[s][e];
		sum2 += dist2[s][e];
	}

	if(sum1 < sum2) cout << "Yes";
	else cout << "No";
}

//그렇게 어려운 문제 아니다...
//그냥 구현구현구현 문제이니 잘 읽어보는게 중요하다.