#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int T, K, C, visiting, home, gap, remain;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> K >> C;
		while (C--) {
			cin >> visiting >> home;
			gap = abs(visiting - home);
			remain = K - max(visiting, home);

			if (visiting == home) cout << "1" << endl;
			else if (visiting < home) {
				if (gap - remain <= 1) cout << "1" << endl;
				else cout << "0" << endl;
			}
			else {
				if (gap - remain <= 2) cout << "1" << endl;
				else cout << "0" << endl;
			}
		}
	}
	return 0;
}