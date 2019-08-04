#include <bits/stdc++.h>
using namespace std;
int tc;
int main() {
	while(++tc) {
		set<int> component, leaf;
		int a, b, node_cnt = 0;
		while(1) {
			scanf("%d%d", &a, &b);
			if(a == b && a == -1) break;
			if(a == b && a == 0) break;
			component.insert(b);
			component.insert(a);
			leaf.insert(b);
			node_cnt++;
		}
		if(a == b && a == -1) break;
		printf("Case %d ", tc);
		if(!node_cnt || (node_cnt == leaf.size() && node_cnt + 1 == component.size()))puts("is a tree.");
		else puts("is not a tree.");
	}
}

//나중에 추가