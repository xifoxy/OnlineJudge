#include <bits/stdc++.h>
using namespace std;
int x, y, w, h;
int main() {
	cin >> x >> y >> w >> h;
	cout << min(min(x, w - x), min(y, h - y)) << '\n';
}

// ¼öÇÐ