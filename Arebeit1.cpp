#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T = 0;
	int p = 0;
	int n = 0;
	int change = 0;
	int num = 0;
	int q = 0;

	cin >> T;
	if (1 <= T && T <= 500000) {
		int Case = T;
		while (Case != 0) {
			cin >> p;
			if (1 <= p && p <= 10000) {
				change = 10000 - p;
				cin >> n;
				if (1 <= n && n <= 14) {
					int* storage = new int[n];		// 동전 종류 저장할 동적배열 생성
					for (int i = 0; i < n; i++) {
						cin >> storage[i];			// 동전 종류 저장
					}
					for (int i = n; i > 0; i--) {
						q = (int)(change / storage[i - 1]);
						change -= (q * storage[i - 1]);
						num += q;
					}
					if (change == 0) {
						cout << num << endl;
					}
					else {
						cout << "0" << endl;
					}
					num = 0;
				}
			}
			Case--;
		}
		cout << endl;
	}
	else {
		cout << endl;
	}
	return 0;
}