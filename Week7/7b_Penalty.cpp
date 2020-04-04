#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> K;
		int C;
		cin >> C;
		while (C--) {
			int visiting;
			int home;
			cin >> visiting;
			cin >> home;
			int gap = abs(visiting - home);
			int remain = K - max(visiting, home);

			if (visiting == home) {
				cout << "1" << endl;
			}
			else if (visiting < home) {
				if (gap - remain <= 1) {
					cout << "1" << endl;
				}
				else {
					cout << "0" << endl;
				}
			}
			else {
				if (gap - remain <= 2) {
					cout << "1" << endl;
				}
				else {
					cout << "0" << endl;
				}
			}
		}
	}
	return 0;
}
