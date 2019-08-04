#include <iostream>
using namespace std;
int main() {
	for(int i = 0; i < 3; ++i) {
		int sum = 0, a;
		for(int j = 0; j < 4; ++j) {
			cin >> a;
			sum += a;
		}
		if(sum == 4 || !sum)
			cout << (!sum ? 'D' : 'E') << '\n';
		else
			cout << (sum != 3 ? sum == 1 ? 'C' : 'B' : 'A') << '\n';
	}
}

//»ý·«